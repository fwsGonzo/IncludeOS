#define X(x) (((x) / 256 | (x)*256) % 65536)

static const unsigned short table[] = {
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    X(0x200), X(0x200), X(0x200), X(0x200), X(0x200),
	X(0x200), X(0x200), X(0x200), X(0x200), X(0x320), X(0x220), X(0x220),
	X(0x220), X(0x220), X(0x200), X(0x200), X(0x200), X(0x200), X(0x200),
	X(0x200), X(0x200), X(0x200), X(0x200), X(0x200), X(0x200), X(0x200),
	X(0x200), X(0x200), X(0x200), X(0x200), X(0x200), X(0x200), X(0x160),
	X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0),
	X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0),
	X(0x4c0), X(0x8d8), X(0x8d8), X(0x8d8), X(0x8d8), X(0x8d8), X(0x8d8),
	X(0x8d8), X(0x8d8), X(0x8d8), X(0x8d8), X(0x4c0), X(0x4c0), X(0x4c0),
	X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x8d5), X(0x8d5), X(0x8d5),
	X(0x8d5), X(0x8d5), X(0x8d5), X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5),
	X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5),
	X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5), X(0x8c5),
	X(0x8c5), X(0x8c5), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0), X(0x4c0),
	X(0x4c0), X(0x8d6), X(0x8d6), X(0x8d6), X(0x8d6), X(0x8d6), X(0x8d6),
	X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6),
	X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6),
	X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x8c6), X(0x4c0),
	X(0x4c0), X(0x4c0), X(0x4c0), X(0x200), 0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,	    0,
	0,	  0,	    0,	      0,	0,	  0,
};

static const unsigned short *const ptable = table + 128;

const unsigned short **__ctype_b_loc(void)
{
	return (void *)&ptable;
}
