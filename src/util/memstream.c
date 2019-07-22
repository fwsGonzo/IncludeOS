#include <util/memstream.h>
#include <x86intrin.h>

void* streamcpy(void* dest, const void* srce, size_t n)
{
  char* dst       = (char*) dest;
  const char* src = (const char*) srce;

  // copy up to 15 bytes until SSE-aligned
  while (((intptr_t) dst & (SSE_SIZE-1)) && n)
  {
    *dst++ = *src++; n--;
  }
  // copy SSE-aligned
  while (n >= SSE_SIZE)
  {
    __m128i data = _mm_load_si128((__m128i*) src);
    _mm_stream_si128((__m128i*) dst, data);

    dst += SSE_SIZE;
    src += SSE_SIZE;

    n -= SSE_SIZE;
  }
  // copy remainder
  while (n--)
  {
    *dst++ = *src++;
  }
  return dst;
}
void* streamucpy(void* dest, const void* usrc, size_t n)
{
  char* dst       = (char*) dest;
  const char* src = (const char*) usrc;

  // copy up to 15 bytes until SSE-aligned
  while (((intptr_t) dst & (SSE_SIZE-1)) && n)
  {
    *dst++ = *src++; n--;
  }
  // copy SSE-aligned
  while (n >= SSE_SIZE)
  {
    __m128i data = _mm_loadu_si128((__m128i*) src);
    _mm_stream_si128((__m128i*) dst, data);

    dst  += SSE_SIZE;
    src += SSE_SIZE;

    n -= SSE_SIZE;
  }
  // copy remainder
  while (n--)
  {
    *dst++ = *src++;
  }
  return dst;
}

static inline char* stream_fill(char* dst, size_t* n, const __m128i data)
{
  while (*n >= SSE_SIZE)
  {
    _mm_stream_si128((__m128i*) dst, data);

    dst += SSE_SIZE;
    *n  -= SSE_SIZE;
  }
  return dst;
}

void* streamset8(void* dest, int8_t value, size_t n)
{
  char* dst = dest;

  // memset up to 15 bytes until SSE-aligned
  while (((intptr_t) dst & (SSE_SIZE-1)) && n)
  {
    *dst++ = value; n--;
  }
  // memset SSE-aligned
  const __m128i data = _mm_set1_epi8(value);
  dst = stream_fill(dst, &n, data);
  // memset remainder
  while (n--)
  {
    *dst++ = value;
  }
  return dst;
}
void* streamset16(void* dest, int16_t value, size_t n)
{
  // memset SSE-aligned
  const __m128i data = _mm_set1_epi16(value);
  return stream_fill((char*) dest, &n, data);
}
void* streamset32(void* dest, int32_t value, size_t n)
{
  // memset SSE-aligned
  const __m128i data = _mm_set1_epi32(value);
  return stream_fill((char*) dest, &n, data);
}
