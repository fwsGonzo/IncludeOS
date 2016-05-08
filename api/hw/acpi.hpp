// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <cstdint>
#include <vector>

namespace hw {
  
  class ACPI {
  public:
    struct LAPIC {
      uint8_t  type;
      uint8_t  length;
      uint8_t  cpu;
      uint8_t  id;
      uint32_t flags;
    };
    typedef std::vector<LAPIC> lapic_list_t;
    
    static void init() {
      get().discover();
    }
    
    static uint64_t time();
    
    static ACPI& get() {
      static ACPI acpi;
      return acpi;
    }
    
    static const lapic_list_t& get_lapics() {
      return get().lapics;
    }
    
  private:
    void discover();
    bool checksum(const char*, size_t) const;
    void begin(const void* addr);
    
    void walk_sdts(const char* addr);
    void walk_madt(const char* addr);
    
    uintptr_t hpet_base;
    uintptr_t apic_base;
    lapic_list_t lapics;
  };
  
}
