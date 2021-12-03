/*
 * @Author       : Chivier Humber
 * @Date         : 2021-09-15 21:15:24
 * @LastEditors  : Chivier Humber
 * @LastEditTime : 2021-11-23 16:08:51
 * @Description  : file content
 */
#include "common.h"
#include "memory.h"

namespace virtual_machine_nsp {
	void memory_tp::ReadMemoryFromFile(std::string filename, int beginning_address) {
		// Read from the file
		// TO BE DONE
		std::ifstream input_file;
		input_file.open(filename);
		std::string line;
		int curr_address = beginning_address;
		if (input_file.is_open())
		{
			while (std::getline(input_file, line))
			{
				while (1)
				{
					if (line.find(' ') == std::string::npos)
						break;
					else
						line = line.replace(line.find(' '), 1, "");
				}
				memory[curr_address] = TranslateInstruction(line);
				curr_address++;
			}
		}
		else
		{
			for (int i = 0; i < 0xFFFF; i++)
				memory[i] = 0;
		}
	}

	int16_t memory_tp::GetContent(int address) const {
		// get the content
		// TO BE DONE
		return memory[address];
	}

	int16_t& memory_tp::operator[](int address) {
		// get the content
		// TO BE DONE
		return memory[address];
	}
}; // virtual machine namespace