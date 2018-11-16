
#include "Bitwise.hpp"
#include "Log.hpp"

class CycleData {

public:

	uint8_t id;
	uint16_t a1_pulse;
	uint16_t a2_pulse;
	uint16_t b1_pulse;
	uint16_t b2_pulse;

	constexpr CycleData(uint64_t data) :
		a1_pulse(bitwise::get_part<0, 14>(data)),
		a2_pulse(bitwise::get_part<14, 28>(data)),
		b1_pulse(bitwise::get_part<28, 42>(data)),
		b2_pulse(bitwise::get_part<42, 56>(data)),
		      id(bitwise::get_part<56, 64>(data)) { }
};

int main() {

  String spes = "gres";

  Info(String("fsdfsdfsd/fsdfsdf/sdfsdfs/dfsdf/sdf/karamel.ffsd").fileName())
  Info(spes + 5);

  Info(bitwise::to_string(7));


  Info(typeid(bitwise::fits<33>).name());

  Info(CycleData(0b00000111'00000000000111'00000000000111'00000000000111'00000000000111).a1_pulse)

  return 0;
}
