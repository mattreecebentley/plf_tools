#define PLF_INCLUDE_BIT_TOOLS
#include "plf_tools.h"

#include <cstdio>
#include <cstdlib>
#include <limits>



void failpass(const char *test_type, bool condition)
{
	printf("%s: ", test_type);

	if (condition)
	{
		printf("Pass\n");
	}
	else
	{
		printf("Fail. Press ENTER to quit.");
		getchar();
		abort();
	}
}



// Bit-by-bit reference implementations to check the plf:: versions against:

template <typename storage_type>
std::size_t reference_countr_zero(const storage_type value)
{
	std::size_t total = 0;

	for (std::size_t bit_index = 0; bit_index != sizeof(storage_type) * 8 && !(value & (storage_type(1) << bit_index)); ++bit_index)
	{
		++total;
	}

	return total;
}



template <typename storage_type>
std::size_t reference_countl_zero(const storage_type value)
{
	std::size_t total = 0;

	for (std::size_t bit_index = sizeof(storage_type) * 8; bit_index-- != 0 && !(value & (storage_type(1) << bit_index));)
	{
		++total;
	}

	return total;
}



// countr_zero/countl_zero require value != 0, countr_one/countl_one require value != max:
template <typename storage_type>
bool check_value(const storage_type value)
{
	bool result = true;

	if (value != 0)
	{
		result = result && plf::countr_zero(value) == reference_countr_zero(value);
		result = result && plf::countl_zero(value) == reference_countl_zero(value);
	}

	if (value != std::numeric_limits<storage_type>::max())
	{
		const storage_type inverse = static_cast<storage_type>(~value);
		result = result && plf::countr_one(value) == reference_countr_zero(inverse);
		result = result && plf::countl_one(value) == reference_countl_zero(inverse);
	}

	if (!result)
	{
		printf("Mismatch for %u-bit value %llx\n", static_cast<unsigned int>(sizeof(storage_type) * 8), static_cast<unsigned long long>(value));
	}

	return result;
}



// Every value for types of 16 bits or fewer:
template <typename storage_type>
bool check_all_values()
{
	bool result = true;
	storage_type value = 0;

	do
	{
		result = check_value(value) && result;
	} while (++value != 0);

	return result;
}



// Wider types - every single set bit and single unset bit, plus runs of ones from either end:
template <typename storage_type>
bool check_bit_patterns()
{
	const storage_type max = std::numeric_limits<storage_type>::max();
	bool result = true;

	for (std::size_t bit_index = 0; bit_index != sizeof(storage_type) * 8; ++bit_index)
	{
		const storage_type bit = static_cast<storage_type>(storage_type(1) << bit_index);
		result = check_value(bit) && result;
		result = check_value(static_cast<storage_type>(~bit)) && result;
		result = check_value(static_cast<storage_type>(max << bit_index)) && result;
		result = check_value(static_cast<storage_type>(max >> bit_index)) && result;
	}

	return result;
}



int main()
{
	failpass("unsigned char, all values", check_all_values<unsigned char>());
	failpass("unsigned short, all values", check_all_values<unsigned short>());
	failpass("unsigned int, bit patterns", check_bit_patterns<unsigned int>());
	failpass("unsigned long, bit patterns", check_bit_patterns<unsigned long>());

	#if __cplusplus >= 201103L
		failpass("unsigned long long, bit patterns", check_bit_patterns<unsigned long long>());
	#endif

	failpass("std::size_t, bit patterns", check_bit_patterns<std::size_t>());

	printf("Press ENTER to quit");
	getchar();
	return 0;
}
