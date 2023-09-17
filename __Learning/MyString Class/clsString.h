#include <iostream>

using namespace std;

namespace MG
{
	static size_t Strlen(const char *S) noexcept
	{
		size_t Counter = 0;
		while (S[Counter] != '\0')
			Counter++;
		return Counter;
	}

	class String
	{
	private:
		char *_Str;
		char _fuck_off = '\0';
		const char _emptyStr[1] = "";
		size_t _size;
		bool _Empty = true; // to check if (_Str == _emptyStr) or not

		char *StrCopy(char *des, const char *Src) const noexcept
		{
			size_t pos = 0;
			while (pos <= _size)
				des[pos] = Src[pos++];
			return des;
		}
		char *StrCopy(char *des, const char *Src, size_t n) const noexcept
		{
			size_t pos = 0;
			while (pos <= n)
				des[pos] = Src[pos++];
			des[n] = '\0'; // make sure that the last char is NULL
			return des;
		}
		char *StrCopy(char *des, const char *Src, size_t Src_pos, size_t len) const noexcept
		{
			size_t pos = 0, end = Src_pos + len;
			while (Src_pos <= end)
				des[pos++] = Src[Src_pos++];
			des[len] = '\0'; // make sure that the last char is NULL
			return des;
		}

	public:
		static constexpr size_t npos = static_cast<size_t>(-1); // 18446744073709551615

		// default constructor
		String() : _size(0), _Str(const_cast<char *>(_emptyStr)), _Empty(true) {}

		String(const char *S) : _size(Strlen(S)), _Empty(false) { StrCopy((_Str = new char[_size + 1]), S); }
		String(const char *S, size_t n) : _Empty(false)
		{
			size_t len = Strlen(S);
			_size = (n > len) ? len : n;
			StrCopy((_Str = new char[_size + 1]), S, _size);
		}

		String(size_t n, char ch) : _size(n), _Empty(false)
		{
			// fill with (n) characters of 'ch'
			_Str = new char[_size + 1];
			size_t i(0);
			while (i < n)
				_Str[i++] = ch;
			_Str[n] = '\0';
		}

		// copy constructor
		// to avoid sharing memory location
		// and make each object have its own memory location
		String(const String &Obj) : _size(Obj._size), _Empty(false) { StrCopy((_Str = new char[_size + 1]), Obj._Str); }

		String(const String &Obj, size_t pos, size_t len = npos)
		{
			if (len != 0 && pos < Obj._size)
			{
				_size = (len == npos || pos + len >= Obj._size) ? Obj._size - pos : len;
				StrCopy((_Str = new char[_size + 1]), Obj._Str, pos, _size);
				_Empty = false;
			}
			else
			{
				clear();
			}
		}

		// move constructor - to avoid coping data when assign a temporary
		String(String &&Obj) noexcept : _Str(Obj._Str), _size(Obj._size), _Empty(false)
		{
			Obj._size = 0;
			Obj._Empty = true;
			Obj._Str = const_cast<char *>(Obj._emptyStr);
		}

		~String()
		{
			if (!_Empty)
			{
				delete[] _Str;
				_Str = nullptr;
			}
		}

		size_t size() const { return _size; }

		void clear()
		{
			if (!_Empty)
			{
				delete[] _Str;
				_size = 0, _Str = const_cast<char *>(_emptyStr), _Empty = true;
			}
		}

		bool Empty() const noexcept { return _Empty; }

		char &operator[](size_t index)
		{
			if (_Empty)
				return _fuck_off;
			return _Str[index];
		}
		const char &operator[](size_t index) const
		{
			if (_Empty)
				return _fuck_off;
			return _Str[index];
		}

		String &operator=(char ch)
		{
			if (!_Empty)
				delete[] _Str;
			_Str = new char[(_size = 1) + 1];
			_Str[0] = ch, _Str[1] = '\0';
			_Empty = false;
			return *this;
		}
		String &operator=(const char *Str)
		{
			if (!_Empty)
				delete[] _Str;
			StrCopy((_Str = new char[(_size = Strlen(Str)) + 1]), Str);
			_Empty = false;
			return *this;
		}
		String &operator=(const String &Obj)
		{
			if (!_Empty)
				delete[] _Str;
			StrCopy((_Str = new char[(_size = Obj._size) + 1]), Obj._Str);
			_Empty = false;
			return *this;
		}
		String &operator=(String &&Obj) noexcept
		{
			// move assignment operator =
			// check if the addresses are the same first
			// because if the addresses are the same this mean that
			// we are moving the same object to itself and this can't be done
			if (this != &Obj)
			{
				if (!_Empty)
					delete[] _Str;																																// deallocate this first if not empty
				_Str = Obj._Str, _size = Obj._size, _Empty = false;															// move the date
				Obj._size = 0, Obj._Empty = true, Obj._Str = const_cast<char *>(Obj._emptyStr); // clear Obj
			}
			return *this;
		}

		/*String& operator +=(char ch)
		{
			return *this;
		}
		String& operator +=(const char* Str)
		{
			return *this;
		}
		String& operator +=(const String& Obj)
		{
			return *this;
		}*/

		friend ostream &operator<<(ostream &, const String &);
		friend istream &operator>>(istream &, String &);

		void print(const char *txt)
		{
			printf("%s%s", txt, _Str);
		}

		// << operator overload for ostream cout
		friend ostream &operator<<(ostream &os, const String &S)
		{
			os << S._Str;
			return os;
		}

		friend istream &operator>>(istream &is, String &S)
		{
			is >> S._Str;
			S._size = Strlen(S._Str);
			return is;
		}
	};

	// an object can be used any where as extern
	extern String Obj;

}