#pragma once

#include <bits/stdc++.h>

namespace MG
{
	namespace algorithm
	{
		template <typename _Ty>
		constexpr void swap(_Ty &Var1, _Ty &Var2)
		{
			_Ty temp = std::move(Var1);
			Var1 = std::move(Var2);
			Var2 = std::move(temp);
		}

		static constexpr size_t next_power_of_2(size_t N)
		{
			--N;
			N |= (N >> 1);
			N |= (N >> 2);
			N |= (N >> 4);
			N |= (N >> 8);
			N |= (N >> 16); // 32 bit number
			// N |= (N >> 32); // 64 bit number
			return ++N;
		}

		static constexpr bool is_power_of_2(long long N)
		{
			return (N > 0 && !(N & (N - 1)));
		}

		// reverse a rang of elements
		// the input range must be a valid rang to avoid any data lose
		template <typename _Iterator>
		static constexpr void reverse(_Iterator _First, _Iterator _Last) noexcept
		{
			for (; _First < _Last; ++_First)
			{
				swap(*_First, *--_Last);
			}
		}
	}

	namespace utility
	{
		namespace str_util
		{

			std::string to_string(int _Num)
			{
				if (_Num == 0)
					return "0";

				bool _isNegative(false);

				if (_Num < 0)
					_isNegative = true, _Num = -_Num;

				std::string s_Num;

				for (; _Num > 0; _Num /= 10)
					s_Num += ((_Num % 10) + '0'); // ex: 1 + 48 = 49 in ascii table

				if (_isNegative)
					s_Num += '-';

				return {s_Num.crbegin(), s_Num.crend()};
			}

			static uint64_t Strlen(const char *S)
			{
				uint64_t Counter = 0;
				while (S[Counter] != '\0')
					Counter++;
				return Counter;
			}
			static uint64_t Strlen(const std::string &S)
			{
				uint64_t Counter = 0;
				while (S[Counter] != '\0')
					Counter++;
				return Counter;
			}
			static uint64_t Strlen(const std::string &Str, uint64_t pos = 0) noexcept
			{
				// length from index 'pos'
				uint64_t Count(0);
				for (uint64_t i(pos); Str[i] != '\0'; i++)
					Count++;
				return Count;
			}

			static char *StrCopy(char *des, const char *Src)
			{
				uint64_t pos = 0, len = Strlen(Src);
				while (pos <= len)
					des[pos] = Src[pos++];
				return des;
			}
			static char *StrCopy(char *des, const char *Src, uint64_t n)
			{
				uint64_t pos = 0;
				while (pos <= n)
					des[pos] = Src[pos++];
				des[n] = '\0'; // make sure that the last char is NULL
				return des;
			}
			static char *StrCopy(char *des, const char *Src, uint64_t Src_pos, uint64_t len)
			{
				uint64_t pos = 0, end = Src_pos + len;
				while (Src_pos <= end)
					des[pos++] = Src[Src_pos++];
				des[len] = '\0'; // make sure that the last char is NULL
				return des;
			}

			static const std::string &Reverse_Str(std::string &Str)
			{
				std::string R_str;
				long long i = (long long)(Str.length() - 1);

				for (i; i >= 0; i--)
					R_str += Str[i];

				return (Str = R_str);
			}
			static char *Reverse_Str(char *Str)
			{
				uint64_t Str_len(Strlen(Str));
				if (Str_len > 1)
				{

					// allocate heap memory
					char *R_str = new char[Str_len + 1];
					long long i(Str_len - 1), j(0);

					// reverse loop
					while (i >= 0)
						R_str[j++] = Str[i--];
					R_str[j] = '\0'; // terminate with '\0'

					// copy after reverse
					StrCopy(Str, R_str, Str_len);

					// deallocate R_str
					delete[] R_str;
					R_str = nullptr;
				}
				return Str;
			}
			static std::string Revers_Str_c(const std::string &Str)
			{
				// using stirng constructor
				return std::string(Str.rbegin(), Str.rend());
			}

			static char invertCase(const char C)
			{
				return std::islower(C) ? std::toupper(C) : std::tolower(C);
			}

			static bool ispalindrom_string(const std::string &Str)
			{
				return (Str == std::string(Str.crbegin(), Str.crend()));
			}

			//---------------------Compare 2 std::strings------------------
			static uint32_t _chars_sum(const std::string &Str) noexcept
			{
				uint32_t _sum(0);
				uint64_t i(0), len(Str.size());
				while (i < len)
					_sum += Str[i++];
				return _sum;
			}
			static uint32_t _chars_sum(const char *const Str) noexcept
			{
				uint32_t _sum(0);
				uint64_t i(0), len(Strlen(Str));
				while (i < len)
					_sum += Str[i++];
				return _sum;
			}

			static int compare(const std::string &S1, const std::string &S2) noexcept
			{
				int _res = (int)(_chars_sum(S1) - _chars_sum(S2));
				return (_res > 0) ? 1 : ((_res < 0) ? -1 : 0);
			}
			static int compare(const char *S1, const char *S2) noexcept
			{
				int _res = (int)(_chars_sum(S1) - _chars_sum(S2));
				return (_res > 0) ? 1 : ((_res < 0) ? -1 : 0);
			}
			//--------------------------------------------------------

			static void swap_string(std::string &S1, std::string &S2) noexcept
			{
				algorithm::swap(S1, S2);
			}

			static const std::string &to_upper(std::string &Str)
			{
				uint64_t size(Str.size()), i(0);
				while (i < size)
					Str[i] = std::toupper(Str[i]), i++;
				return Str;
			}
			static char *to_upper(char *Str)
			{
				uint64_t size(Strlen(Str)), i(0);
				while (i < size)
					Str[i] = std::toupper(Str[i]), i++;
				return Str;
			}

			static const std::string &to_lower(std::string &Str)
			{
				uint64_t size(Str.size()), i(0);
				while (i < size)
					Str[i] = std::tolower(Str[i]), i++;
				return Str;
			}
			static char *to_lower(char *Str)
			{
				uint64_t size(Strlen(Str)), i(0);
				while (i < size)
					Str[i] = std::tolower(Str[i]), i++;
				return Str;
			}

			static bool is_digits(const std::string &Str)
			{
				uint64_t size(Str.size()), i(0);
				
				while (i < size)
					if (!std::isdigit(Str[i++]))
						return false;

				return true;
			}
			static bool is_digits(const std::string &Str, uint64_t pos)
			{
				uint64_t len(Str.size()), i(pos);
				while (i < len)
					if (!std::isdigit(Str[i++]))
						return false;
				return true;
			}
			static bool is_digits(const char *Str)
			{
				uint64_t size(Strlen(Str)), i(0);
				while (i < size)
					if (!std::isdigit(Str[i++]))
						return false;
				return true;
			}
			static bool is_digits(const char *Str, uint64_t pos)
			{
				uint64_t len(Strlen(Str)), i(pos);
				while (i < len)
					if (!std::isdigit(Str[i++]))
						return false;
				return true;
			}

			static bool is_n_chars(const std::string &Str, uint32_t n)
			{
				return (Str.size() == n);
			}
			static bool is_n_chars(const char *const Str, uint32_t n)
			{
				return (Strlen(Str) == n);
			}

			static bool is_digits_of_n(const std::string &Str, uint32_t n)
			{
				return is_digits(Str) && is_n_chars(Str, n);
			}
			static bool is_digits_of_n(const char *const Str, uint32_t n)
			{
				return is_digits(Str) && is_n_chars(Str, n);
			}

			static const std::string &invertCases(std::string &Str)
			{
				uint64_t size(Str.size()), i(0);
				while (i < size)
					Str[i] = invertCase(Str[i]), i++;
				return Str;
			}

			std::vector<std::string> split_str(const std::string &_Str, std::string_view delim = " ", const int Hint = 0)
			{
				if (_Str.empty())
					return {};

				size_t len(_Str.size()), idx(0), found(0);
				std::vector<std::string> Words;

				// Hint => the number of elements
				if (Hint)
					Words.reserve(Hint);

				for (; (found = _Str.find(delim, idx)) != std::string::npos; idx = found + delim.size())
					if (found != idx)
						Words.push_back(_Str.substr(idx, found - idx));

				if (len != idx)
					Words.push_back(_Str.substr(idx, len - idx));

				return Words;
			}

			static std::string join_string(const std::vector<std::string> &vWords, const char *delim = " ") noexcept
			{
				std::string Str;
				uint64_t vsize(vWords.size()), i(0);

				while (i < vsize)
				{
					if (i == vsize - 1)
					{
						Str += vWords[i];
						break;
					}
					Str += (vWords[i++] + delim);
				}
				return Str;
			}

			// find() no case-sensitive
			static uint64_t find_noCs(const std::string &Str, char ch, uint64_t pos = 0) noexcept
			{
				uint64_t len = Str.size();
				ch = std::tolower(ch); // make lower

				for (uint64_t i(pos); i < len; i++)
					if (std::tolower(Str[i]) == ch)
						return i;

				return std::string::npos;
			}
			static uint64_t find_noCs(const std::string &Str, const char *S, uint64_t pos = 0) noexcept
			{
				uint64_t S_len = Strlen(S), Str_len = Str.size();

				if (S_len == 1)
					return find_noCs(Str, S[0], pos);

				uint64_t Target_index(0);

				for (uint64_t Str_index(pos); Str_index < Str_len; Str_index++)
				{
					if (std::tolower(Str[Str_index]) == std::tolower(S[0]))
					{
						Target_index = Str_index;

						for (uint64_t S_index(1); S_index < S_len; S_index++)
						{
							Str_index++;

							if (std::tolower(S[S_index]) != std::tolower(Str[Str_index]))
								break;

							if (S_index == S_len - 1 && std::tolower(S[S_index]) == std::tolower(Str[Str_index]))
								return Target_index;
						}
					}
				}
				return std::string::npos;
			}
			static uint64_t find_noCs(const std::string &Str, const std::string &S, const uint64_t pos = 0) noexcept
			{
				uint64_t S_len = S.size(), Str_len = Str.size();

				// when "S" is just a character
				if (S_len == 1)
					return find_noCs(Str, S[0], pos);

				uint64_t Target_index(0);

				for (uint64_t Str_index = pos; Str_index < Str_len; Str_index++)
				{
					if (std::tolower(Str[Str_index]) == std::tolower(S[0])) // When first character equal to first character of "S"
					{
						Target_index = Str_index; // Make the Target_index = index of first character of word

						// Search for the other characters of "S"
						for (uint64_t S_index = 1; S_index < S_len; S_index++)
						{
							Str_index++;

							if (std::tolower(S[S_index]) != std::tolower(Str[Str_index]))
								break; // Break this loop if any char of "S" not equal to "Str" char

							if (S_index == S_len - 1 && std::tolower(S[S_index]) == std::tolower(Str[Str_index]))
								return Target_index; // if all character found
						}
					}
				}
				return std::string::npos;
			}

			// ( Cs ) --> Case Sensitive
			static std::string replace_words_Cs(std::string &Str, const std::string &old_word, const std::string &new_word)
			{
				uint16_t old_word_len((uint16_t)old_word.size());
				uint16_t new_word_len((uint16_t)new_word.size());
				uint64_t found(Str.find(old_word));

				while (found != std::string::npos)
				{

					Str.replace(found, old_word_len, new_word);
					found = Str.find(old_word, found + new_word_len); // optimize
				}
				return Str;
			}
			static std::string replace_words_Cs(std::string &Str, const char *old_word, const char *new_word)
			{
				uint16_t old_word_len = (uint16_t)Strlen(old_word);
				uint16_t new_word_len = (uint16_t)Strlen(new_word);

				uint64_t found(Str.find(old_word));
				while (found != std::string::npos)
				{

					Str.replace(found, old_word_len, new_word);
					found = Str.find(old_word, found + new_word_len); // optimize
				}
				return Str;
			}

			// ( noCs ) --> no Case Sensitive
			static std::string replace_words_noCs(std::string &Str, std::string &old_word, const std::string &new_word)
			{
				uint16_t old_word_len((uint16_t)old_word.size());
				uint16_t new_word_len((uint16_t)new_word.size());

				uint64_t found(find_noCs(Str, old_word));
				while (found != std::string::npos)
				{

					Str.replace(found, old_word_len, new_word);
					found = find_noCs(Str, old_word, found + new_word_len); // optimize
				}
				return Str;
			}
			static std::string replace_words_noCs(std::string &Str, const char *old_word, const char *new_word)
			{
				uint16_t old_word_len = (uint16_t)Strlen(old_word);
				uint16_t new_word_len = (uint16_t)Strlen(new_word);

				uint64_t found = find_noCs(Str, old_word);
				while (found != std::string::npos)
				{

					Str.replace(found, old_word_len, new_word);
					found = find_noCs(Str, old_word, found + new_word_len); // optimize
				}
				return Str;
			}

			static const std::string &remove_blank(std::string &Str)
			{
				// ' ' - '\t'
				uint64_t len(Str.size()), i(0);
				std::string C_str;

				while (i < len)
				{

					if (!isblank(Str[i]))
						C_str += Str[i];
					i++;
				}
				return (Str = C_str);
			}
			static const std::string &remove_punct(std::string &Str)
			{
				// !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
				uint64_t len(Str.size()), i(0);
				std::string C_str;

				while (i < len)
				{
					if (!ispunct(Str[i]))
						C_str += Str[i];
					i++;
				}
				return (Str = C_str);
			}
			static const std::string &remove_ws(std::string &Str)
			{
				// whitespaces:( \f\n\r\t\v)
				uint64_t len(Str.size()), i(0);
				std::string C_str;

				while (i < len)
				{
					if (!isspace(Str[i]))
						C_str += Str[i];
					i++;
				}
				return (Str = C_str);
			}

			static void upper_first_of_each_Word(std::string &Str)
			{
				bool isFirstLetter = true;
				uint64_t len(Str.size());

				for (uint64_t i(0); i < len; i++)
				{
					if (Str[i] != ' ' && isFirstLetter)
						Str[i] = std::toupper(Str[i]);

					isFirstLetter = (Str[i] == ' ') ? true : false;
				}
			}
			static void lower_first_of_each_Word(std::string &Str)
			{
				bool isFirstLetter = true;
				uint64_t len(Str.size());

				for (uint64_t i = 0; i < len; i++)
				{
					if (Str[i] != ' ' && isFirstLetter)
						Str[i] = std::tolower(Str[i]);

					isFirstLetter = (Str[i] == ' ') ? true : false;
				}
			}

			static std::string &l_trim(std::string &Str)
			{
				size_t len(Str.size());

				for (size_t i(0); i < len; ++i)
					if (Str[i] != ' ')
						return (Str = Str.substr(i, len));

				return Str;
			}
			static std::string &r_trim(std::string &Str)
			{
				size_t len(Str.size());

				for (int64_t i = len - 1; i >= 0; --i)
					if (Str[i] != ' ')
						return (Str = Str.substr(0, i + 1));

				return Str;
			}
			static std::string &trim(std::string &Str)
			{
				return r_trim(l_trim(Str));
			}

			static std::string _Encrypt_(std::string _Str, int Enc_Key)
			{
				for (char &C : _Str)
					C = char((int)C + (Enc_Key >> 1));
				return _Str;
			}
			static std::string _Decrypt_(std::string _Str, int Dec_Key)
			{
				for (char &C : _Str)
					C = char((int)C - (Dec_Key >> 1));
				return _Str;
			}

			// Encryption & Decryption Key
			static constexpr int _Key = 77;

			//-------------------------------------------------Number to std::string------------------------------------------------

			static const std::string __1To9[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

			static const std::string __10To19[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

			static const std::string __20To90[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

			static const std::string __Tags[42] = {"", "Thousand", "Million", "Billion", "Trillion", "Quadrillion", "Quintillion",
																						 "Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion", "Undecillion", "Duodecillion",
																						 "Tredecillion", "Quattuordecillion", "Quindecillion", "Sedecillion", "Septendecillion", "Octodecillion",
																						 "Novendecillion", "Vigintillion", "Unvigintillion", "Duovigintillion", "Tresvigintillion",
																						 "Quattuorvigintillion", "Quinvigintillion", "Sesvigintillion", "Septemvigintillion",
																						 "Octovigintillion", "Novemvigintillion", "Trigintillion", "Untrigintillion",
																						 "Duotrigintillion", "Trestrigintillion", "Quattuortrigintillion", "Quintrigintillion",
																						 "Sestrigintillion", "Septentrigintillion", "Octotrigintillion", "Noventrigintillion", "Quadragintillion"};

			// not working with floating-point numbers
			static bool is_valid_snumber(const std::string &sNum)
			{
				if (!(sNum[0] == '-' || (isdigit(sNum[0]) && sNum[0] != '0')))
					return false;

				if (!is_digits(sNum, 1)) // avoid check index[0]
					return false;

				return true;
			}

			static std::string sNumberToText(std::string Number)
			{
				if (is_valid_snumber(Number))
				{
					if (Number == "0")
						return "Zero";

					std::string TxtNum(""), NegativeTag("");
					bool isNegativeNumber = false;
					std::vector<std::string> vRevTxtNum;
					uint16_t ones, tens, hundreds, TagIndex(0);
					uint64_t len;

					if (Number[0] == '-')
					{
						NegativeTag = "Negative";
						isNegativeNumber = true;
						Number.erase(Number.begin());
					}

					while ((len = Number.size()) > 0)
					{
						ones = Number[len - 1] - '0';
						Number.pop_back();

						if (len > 1)
						{
							tens = Number[len - 2] - '0';
							Number.pop_back();
						}
						else
							tens = 0;

						if (len > 2)
						{
							hundreds = Number[len - 3] - '0';
							Number.pop_back();
						}
						else
							hundreds = 0;

						if (hundreds != 0)
							TxtNum += __1To9[hundreds] + " Hundred ";

						if (tens == 0)
						{
							if (ones != 0)
								TxtNum += __1To9[ones] + " ";
						}
						else if (tens == 1)
						{
							TxtNum += __10To19[ones] + " ";
						}
						else if (tens > 1)
						{
							TxtNum += __20To90[tens] + " ";

							if (ones != 0)
								TxtNum += __1To9[ones] + " ";
						}

						if (TxtNum != "")
							vRevTxtNum.push_back(TxtNum + __Tags[TagIndex]);

						TagIndex++;
						TxtNum = "";
					}

					if (vRevTxtNum.size() != 0)
					{
						if (isNegativeNumber)
							vRevTxtNum.push_back(NegativeTag); // add negative tag

						std::vector<std::string>::iterator iter = vRevTxtNum.end();

						while (iter != vRevTxtNum.begin())
						{
							iter--;
							TxtNum += *iter + " ";
						}

						return r_trim(TxtNum);
					}
				}
				return "Not A Valid Number :-(";
			}
			//-----------------------------------------------------------------------------------------------------------------

		}

		namespace rand_util
		{

			//---------------------------------------- Random ---------------------------------------

			// singleton class
			class Random final
			{
			private:
				static uint32_t _Next;
				static constexpr int Rand_Max = 32767;

			public:
				// disable default/copy/move constructors
				// no one can create an instance
				Random() = delete;
				Random(const Random &) = delete;
				Random(Random &&) = delete;
				// disable copy/move assignment operators
				Random &operator=(const Random &) = delete;
				Random &operator=(Random &&) = delete;

				// initiate the _Next member
				static void srand(uint32_t seed)
				{
					_Next = seed;
				}

				// generate random integer number
				static uint32_t irand(void)
				{
					// Rand_Max = 32767
					_Next = _Next * 123456789 + 12345;
					return (_Next >> 15) % (Rand_Max + 1);
				}

				// generate random double number
				static double frand(void)
				{
					// Rand_Max = 32767
					_Next = _Next * 123456789 + 12345;
					return std::fmod(_Next / 12345.6789, (Rand_Max + 1));
				}

				// generate random integer number (from -> to)
				static int32_t irrand(int32_t from, int32_t to)
				{
					return irand() % (to - from + 1) + from;
				}

				// generate random double number (from -> to)
				static double frrand(double from, double to)
				{
					return from + (frand() / (double)Rand_Max) * (to - from);
				}
			};
			// initialize the Random static member
			uint32_t Random::_Next(1);

			static char rand_s_alpha()
			{
				// random small alphabet
				return (char)Random::irrand(97, 122);
			}
			static char rand_c_alpha()
			{
				// random capital alphabet
				return (char)Random::irrand(65, 90);
			}
			static char rand_digit()
			{
				// random special char
				return (char)Random::irrand(48, 57);
			}
			static char rand_aldigit()
			{
				// random (alphabet or digit)
				char alpha_digit[3]{rand_s_alpha(), rand_c_alpha(), rand_digit()};
				return (char)alpha_digit[Random::irrand(0, 2)];
			}
			static char rand_s_aldigit()
			{
				// random (small alphabet or digit)
				char alpha_digit[2]{rand_s_alpha(), rand_digit()};
				return (char)alpha_digit[Random::irrand(0, 1)];
			}
			static char rand_c_aldigit()
			{
				// random (capital alphabet or digit)
				char alpha_digit[2]{rand_c_alpha(), rand_digit()};
				return (char)alpha_digit[Random::irrand(0, 1)];
			}
			static char rand_punc()
			{
				// random Punctuation
				char puncs[4]{
						(char)Random::irrand(33, 47),
						(char)Random::irrand(58, 64),
						(char)Random::irrand(91, 96),
						(char)Random::irrand(123, 126)};
				return (char)puncs[Random::irrand(0, 3)];
			}
			static char rand_graph()
			{
				// random character from ( 33 -> 126 )
				return (char)Random::irrand(33, 126);
			}

			enum en_CharType
			{
				small_alpha = 1,
				capital_alpha = 2,
				digit = 3,
				alpha_digit = 4,
				s_alpha_digit = 5,
				c_alpha_digit = 6,
				punc = 7,
				graph = 8
			};

			// enum: (1) small_alpha - (2) capital_alpha - (3) digit - (4) alpha_digit
			//       (5) s_alpha_digit - (6) c_alpha_digit - (7) punc - (8) graph
			static char random_char(en_CharType char_type)
			{
				switch (char_type)
				{
				case small_alpha:
					return rand_s_alpha();
				case capital_alpha:
					return rand_c_alpha();
				case digit:
					return rand_digit();
				case alpha_digit:
					return rand_aldigit();
				case s_alpha_digit:
					return rand_s_aldigit();
				case c_alpha_digit:
					return rand_c_aldigit();
				case punc:
					return rand_punc();
				case graph:
					return rand_graph();
				default:
					return '\0';
				}
			}

			// enum: (1) small_alpha - (2) capital_alpha - (3) digit - (4) alpha_digit
			//       (5) s_alpha_digit - (6) c_alpha_digit - (7) punc - (8) graph
			static std::string rand_word(en_CharType char_type, uint16_t len)
			{
				std::string Word;
				Word.reserve(len);

				for (short i(0); i < len; ++i)
					Word += random_char(char_type);

				return Word;
			}

			// enum: (1) small_alpha - (2) capital_alpha - (3) digit - (4) alpha_digit
			//       (5) s_alpha_digit - (6) c_alpha_digit - (7) punc - (8) graph
			static std::string rand_key(en_CharType char_type, uint16_t n_words, uint16_t word_len)
			{
				std::string Key;
				Key.reserve((size_t)(word_len * n_words));

				Key += rand_word(char_type, word_len); // add the first word

				for (uint16_t i(1); i < n_words; ++i)
				{
					Key += '-' + rand_word(char_type, word_len);
				}
				return Key;
			}
			//---------------------------------------------------------------------------------------

		}

		namespace num_util
		{

			static uint16_t sum_all_digits(uint64_t Number)
			{
				uint8_t Remainder(0);
				uint16_t Sum(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					Sum += Remainder;
					Number /= 10;
				}
				return Sum;
			}
			static uint16_t sum_all_digits(uint32_t Number)
			{
				uint8_t Remainder(0);
				uint16_t Sum(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					Sum += Remainder;
					Number /= 10;
				}
				return Sum;
			}
			static uint16_t sum_all_digits(uint16_t Number)
			{
				uint8_t Remainder(0);
				uint16_t Sum(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					Sum += Remainder;
					Number /= 10;
				}
				return Sum;
			}

			static uint64_t reverse_number(uint64_t Number)
			{
				uint64_t R_Number(0);
				uint8_t Remainder(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					R_Number = (R_Number + Remainder) * 10;
					Number /= 10;
				}
				return R_Number / 10;
			}
			static uint32_t reverse_number(uint32_t Number)
			{
				uint32_t R_Number(0);
				uint8_t Remainder(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					R_Number = (R_Number + Remainder) * 10;
					Number /= 10;
				}
				return R_Number / 10;
			}
			static uint16_t reverse_number(uint16_t Number)
			{
				uint16_t R_Number(0);
				uint8_t Remainder(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					R_Number = (R_Number + Remainder) * 10;
					Number /= 10;
				}
				return R_Number / 10;
			}

			static uint16_t frequency_of_digit(uint64_t Number, uint8_t digit)
			{
				uint16_t freq(0);
				uint8_t Remainder(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					Number /= 10;
					if (Remainder == digit)
						freq++;
				}
				return freq;
			}
			static uint16_t frequency_of_digit(uint32_t Number, uint8_t digit)
			{
				uint16_t freq(0);
				uint8_t Remainder(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					Number /= 10;
					if (Remainder == digit)
						freq++;
				}
				return freq;
			}
			static uint16_t frequency_of_digit(uint16_t Number, uint8_t digit)
			{
				uint16_t freq(0);
				uint8_t Remainder(0);
				while (Number > 0)
				{
					Remainder = Number % 10;
					Number /= 10;
					if (Remainder == digit)
						freq++;
				}
				return freq;
			}

			static bool is_prime(uint64_t N)
			{
				uint32_t Half_N = (uint32_t)ceil(N / 2), i(2);
				while (i <= Half_N)
					if (N % i++ == 0)
						return false;
				return true;
			}
			static bool is_prime(uint32_t N)
			{
				uint16_t Half_N = (uint16_t)ceil(N / 2), i(2);
				while (i <= Half_N)
					if (N % i++ == 0)
						return false;
				return true;
			}
			static bool is_prime(uint16_t N)
			{
				uint16_t Half_N = (uint16_t)ceil(N / 2), i(2);
				while (i <= Half_N)
					if (N % i++ == 0)
						return false;
				return true;
			}

			static bool is_perfect(uint64_t N)
			{
				uint32_t Half_N = (uint32_t)ceil(N / 2);
				uint16_t sum(0);

				for (uint32_t i(1); i <= Half_N; i++)
					if (N % i == 0)
						sum += i;

				return sum == N;
			}
			static bool is_perfect(uint32_t N)
			{
				uint16_t Half_N = (uint16_t)ceil(N / 2);
				uint16_t sum(0);

				for (uint16_t i(1); i <= Half_N; i++)
					if (N % i == 0)
						sum += i;

				return sum == N;
			}
			static bool is_perfect(uint16_t N)
			{
				uint16_t Half_N = (uint16_t)ceil(N / 2);
				uint16_t sum(0);

				for (uint16_t i(1); i <= Half_N; i++)
					if (N % i == 0)
						sum += i;

				return sum == N;
			}

			static bool is_n_digits(uint64_t num, uint16_t n_digits)
			{
				uint16_t count(0);
				while (num > 0)
					count++, num /= 10;

				return (count == n_digits);
			}
			static bool is_n_digits(uint32_t num, uint16_t n_digits)
			{
				uint16_t count(0);
				while (num > 0)
					count++, num /= 10;

				return (count == n_digits);
			}
			static bool is_n_digits(uint16_t num, uint16_t n_digits)
			{
				uint16_t count(0);
				while (num > 0)
					count++, num /= 10;

				return (count == n_digits);
			}

			// unsigned int
			static bool isNumBetween(uint64_t num, uint64_t from, uint64_t to)
			{
				return (num >= from && num <= to);
			}
			static bool isNumBetween(uint32_t num, uint32_t from, uint32_t to)
			{
				return (num >= from && num <= to);
			}
			static bool isNumBetween(uint16_t num, uint16_t from, uint16_t to)
			{
				return (num >= from && num <= to);
			}

			// signed int
			static bool isNumBetween(int64_t num, int64_t from, int64_t to)
			{
				return (num >= from && num <= to);
			}
			static bool isNumBetween(int32_t num, int32_t from, int32_t to)
			{
				return (num >= from && num <= to);
			}
			static bool isNumBetween(int16_t num, int16_t from, int16_t to)
			{
				return (num >= from && num <= to);
			}

			// floating-point
			static bool isNumBetween(float num, float from, float to)
			{
				return (num >= from && num <= to);
			}
			static bool isNumBetween(double num, double from, double to)
			{
				return (num >= from && num <= to);
			}
			static bool isNumBetween(long double num, long double from, long double to)
			{
				return (num >= from && num <= to);
			}

		}

		namespace input_valid
		{

			// read number
			template <typename Ty>
			static Ty Read_Num(const char *const err_msg = "Invalid Num, Enter Again? ")
			{
				Ty num(0);
				while (!(std::cin >> num))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << err_msg;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return num;
			}

			// read number in range
			template <typename Ty>
			static Ty Read_NumInRange(Ty from, Ty to, const char *const msg)
			{
				Ty num(0);
				std::cout << msg << ", Between [" << from << " -> " << to << "]? ";
				while (!(std::cin >> num) || !((num >= from && num <= to)))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << msg << ", Between [" << from << " -> " << to << "]? ";
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return num;
			}

			// read positive number
			template <typename Ty>
			static Ty Read_pNum(const char *const err_msg = "Invalid Num, Enter A Positive Number? ")
			{
				Ty num(0);
				while (!(std::cin >> num) || !(num > 0))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << err_msg;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return num;
			}

			// read integer number of (n) digits
			static int64_t Read_iNumOfNDigits(uint16_t n_digits)
			{
				int64_t num(0);
				while (!(std::cin >> num) || !(num_util::is_n_digits((uint64_t)num, n_digits)))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid Number, Enter A " << n_digits << " Digit(s) Number? ";
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return num;
			}

			// used to read (yes or no) from the user to confirm something
			static bool Read_YesOrNo(const char *const msg = "")
			{
				std::string S;
				do
				{
					std::cout << msg;
					std::cin >> S;

				} while (!(S == "Y" || S == "y" || S == "N" || S == "n"));

				return (S == "Y" || S == "y");
			}
			// used to read (yes or no) from the user to confirm something
			static bool Read_YesOrNo(const std::string &&msg = "")
			{
				std::string S;
				do
				{
					std::cout << msg;
					std::cin >> S;

				} while (!(S == "Y" || S == "y" || S == "N" || S == "n"));

				return (S == "Y" || S == "y");
			}

			static std::string ReadTxt(const char *const msg = "")
			{
				std::string txt;
				std::cout << msg;
				// std::ws to ignore (white spaces)
				std::getline(std::cin >> std::ws, txt);
				return txt;
			}
		}
	}

}
