/**
* Copyright Johannes Kloimböck 2021 - 2022.
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE or copy at
* https://www.boost.org/LICENSE_1_0.txt)
*/

#include <iostream>
#include <cmath>
#include <cinttypes>
#include <string>

inline int fb_abort() {
	std::cout << "Bad input!" << std::endl;
	std::cout << "Aborting!" << std::endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}

inline std::size_t precision(std::uint64_t ui) noexcept {
	std::size_t c = 0;

	for (; c < 64; ++c) {
		if ((1ULL << (63 - c)) & ui) {
			return (64 - c);
		}
	}

	return 0;
}

inline std::string binaryString(std::uint64_t ui) {
	std::size_t s = precision(ui);

	if (ui == 0ULL) {
		return "0";
	}

	std::string str{};

	for (std::size_t i = 0; i < s; ++i) {
		str += ((1ULL << (s - i - 1)) & ui) ? "1" : "0";
	}

	return str;
}

union float_i64 {
	double f;
	std::uint64_t i;
};

union float_i32 {
	float f;
	std::uint32_t i;
};

int main() {
	unsigned int choice = 0;

	std::cout << "Int to Float.....1" << std::endl;
	std::cout << "Float to Int.....2" << std::endl;

	std::cin >> choice;

	if (choice == 1) {
		std::cout << "\t32-bit......1" << std::endl;
		std::cout << "\t64-bit......2" << std::endl;

		std::cin >> choice;

		if (choice == 1) {
			int base = 10;

			std::cout << "Enter the integer number: ";
			std::string s;
			std::cin >> s;

			std::cout << "\nEnter the radix: " << std::endl;
			std::cin >> base;

			float_i32 fi;
			fi.i = (std::uint32_t)(std::strtoul(s.c_str(), nullptr, base));

			std::cout << std::endl;
			std::printf("%.7g\n", fi.f);
		}
		else if (choice == 2) {
			int base = 10;

			std::cout << "Enter the integer number: ";
			std::string s;
			std::cin >> s;

			std::cout << "\nEnter the radix: ";
			std::cin >> base;

			float_i64 fi;
			fi.i = (std::uint64_t)(std::strtoull(s.c_str(), nullptr, base));

			std::cout << "\n" << std::endl;
			std::printf("%.16g\n", fi.f);
		}
		else {
			return fb_abort();
		}
	}
	else if (choice == 2) {
		std::cout << "\t32-bit......1" << std::endl;
		std::cout << "\t64-bit......2" << std::endl;

		std::cin >> choice;

		if (choice == 1) {
			std::string s;
			std::cout << "Enter the value of the floating-point number: ";
			std::cin >> s;
			float f = strtof(s.c_str(), nullptr);

			float_i32 fi;
			fi.f = f;

			std::cout << "\n" << std::endl;
			std::printf("Bin: %s\n", binaryString(fi.i).c_str());
			std::printf("Oct: %lo\n", fi.i);
			std::printf("Dec: %lu\n", fi.i);
			std::printf("Hex: %lx\n", fi.i);
		}
		else if (choice == 2) {
			std::string s;
			std::cout << "Enter the value of the floating-point number: ";
			std::cin >> s;
			double f = strtod(s.c_str(), nullptr);

			float_i64 fi;
			fi.f = f;

			std::cout << "\n" << std::endl;
			std::printf("Bin: %s\n", binaryString(fi.i).c_str());
			std::printf("Oct: %llo\n", fi.i);
			std::printf("Dec: %llu\n", fi.i);
			std::printf("Hex: %llx\n", fi.i);
		}
		else {
			return fb_abort();
		}
	}
	else {
		return fb_abort();
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
