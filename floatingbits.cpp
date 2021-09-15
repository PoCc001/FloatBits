/**
* Copyright Johannes Kloimböck 2021.
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
			std::printf("%x\n", fi.i);
		}
		else if (choice == 2) {
			std::string s;
			std::cout << "Enter the value of the floating-point number: ";
			std::cin >> s;
			double f = strtod(s.c_str(), nullptr);

			float_i64 fi;
			fi.f = f;

			std::cout << "\n" << std::endl;
			std::printf("%llx\n", fi.i);
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