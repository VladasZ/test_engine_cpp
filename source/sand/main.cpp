
#include "Bitwise.hpp"
#include "Log.hpp"

class CycleData {

public:

	//uint8_t id;
	//uint16_t a1_pulse;
	//uint16_t a2_pulse;
	//uint16_t b1_pulse;
	//uint16_t b2_pulse;
	uint64_t data;

	constexpr CycleData(uint64_t data) : data(data)
		//a1_pulse(bitwise::get_part<0, 14>(data)),
		//a2_pulse(bitwise::get_part<14, 28>(data)),
		//b1_pulse(bitwise::get_part<28, 42>(data)),
		//b2_pulse(bitwise::get_part<42, 56>(data))
	//	      id(bitwise::get_part<56, 64>(data)) 
	{ }
};

int main() {



  auto data = CycleData(0b00000001'00000001'00000001'00000001'00000001'00000001'00000001'00000001);
  Info(bitwise::to_string(data));

  Info(bitwise::to_string(14737632));


  return 0;
}
