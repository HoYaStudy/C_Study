/**
 * @brief Reset Single 1 from LSB
 *
 * @param [in] x : unsigned integer number
 *
 * @return unsigned int
 *
 * @note
 * input = 70 (0b_0100_0110)
 * output = 68 (0b_0100_0100)
 */
const unsigned int reset_lsb_1(const unsigned int x) { return x & (x - 1); }

/**
 * @brief Reset All 1s from LSB
 *
 * @param [in] x : unsigned integer number
 *
 * @return unsigned int
 *
 * @note
 * input = 71 (0b_0100_0111)
 * output = 64 (0b_0100_0000)
 */
const unsigned int reset_lsb_1s(const unsigned int x) { return x & (x + 1); }

/**
 * @brief Reset Only Single LSB 1
 *
 * @param [in] x : unsigned integer number
 *
 * @return unsigned int
 *
 * @note
 * input = 68 (0b_0100_0100)
 * output = 4294967291 (0b_1111_1011)
 */
const unsigned int set_only_lsb_1(const unsigned int x) { return ~x | (x - 1); }

/**
 * @brief Set Single 0 from LSB
 *
 * @param [in] x : unsigned integer number
 *
 * @return unsigned int
 *
 * @note
 * input = 68 (0b_0100_0100)
 * output = 69 (0b_0100_0101)
 */
const unsigned int set_lsb_0(const unsigned int x) { return x | (x + 1); }

/**
 * @brief Set All 0s from LSB
 *
 * @param [in] x : unsigned integer number
 *
 * @return unsigned int
 *
 * @note
 * input = 68 (0b_0100_0100)
 * output = 71 (0b_0100_0111)
 */
const unsigned int set_lsb_0s(const unsigned int x) { return x | (x - 1); }

/**
 * @brief Set Only Single LSB 0
 *
 * @param [in] x : unsigned integer number
 *
 * @return unsigned int
 *
 * @note
 * input = 71 (0b_0100_0111)
 * output = 8 (0b_0000_1000)
 */
const unsigned int set_only_lsb_0(const unsigned int x) { return ~x & (x + 1); }