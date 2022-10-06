#include <string>

using namespace std;

// Convierte una string con digitos binarios a un número de 64 bits
static uint64_t BinaryToNum(string bin) {
    uint64_t c = 0;
    for (size_t i = 0; i < bin.size(); i++) {
        // Se hace un shift a la izquierda para darle espacio al siguiente bit
        c = c << 1;
        // Traduce el caracter al número que le corresponde
        c += bin[i] == '0' ? 0 : 1;
    }
    return c;
}

// Convierte convertir un número de 64 bits a una string con dígitos binarios con una longitud mínima
// de `padding` bits
static string NumToBinary(uint64_t in, size_t padding) {
    string bin;
    uint64_t c = in;

    // Se repite el ciclo hasta no haber más 1s
    while (c != 0) {
        // Inserta un bit 0 o 1 según el bit que esté al final
        if ((c & 0b1) == 0) {
            bin.insert(bin.begin(), '0');
        } else {
            bin.insert(bin.begin(), '1');
        }
        // Y se continua con el siguiente bit
        c = c >> 1;
    }

    // Se completa la string a `padding` bits
    while (bin.size() < padding) {
        bin.insert(bin.begin(), '0');
    }

    return bin;
}

// Convierte una string a una string con su representación binaria
static string ASCIIToBinary(string str) {
	string bin;

    // Recorre cada caracter de la string convirtiendolo en sus representaciones binarias de 8 bits
	for (size_t i = 0; i < str.size(); ++i)
	{
		string cBin = NumToBinary(str[i], 8);
		bin.append(cBin);
	}

	return bin;
}

// Convierte un dígito hexadecimal a su valor numérico
static char hexCharToNum(char hex) {
    // Por facilidad, convertimos todo a minúsculas
    char input = tolower(hex);
    char c = 0;

    // Revisamos si son caracteres válidos de hexadecimal
    if (isalpha(input) && input >= 'a' && input <= 'f') {
        // Si el dígito es A-F
        // Ya que un char solo es un número, podemos restarle 'a', dándonos
        // 'a' - 'a' = 0
        // 'b' - 'a' = 1
        // 'c' - 'a' = 2
        // etc.
        // Y si le sumamos 10, obtenemos su valor numérico según hexadecimal
        c = input - 'a' + 10;
    } else if (isdigit(input)) {
        // Si el dígito es 0-9
        // De la misma manera, podemos restarle '0', dándonos
        // '0' - '0' = 0
        // '1' - '0' = 1
        // etc.
        c = input - '0';
    }

    return c;
}

// Convierte una cadena hexadecimal a su representación binaria
static string hexToBinary(string hex) {
    string key;
    for (size_t i = 0; i < hex.size(); i++) {
        // Convertimos el dígito a su valor numérico
        int c = hexCharToNum(hex[i]);
        // y convertimos ese valor numérico a su representación binaria en 4 bits
        key.append(NumToBinary(c, 4));
    }
    return key;
}

// Mapeado de valores numéricos a caracteres hexadecimales
static char hexChars[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

// Convierte una cadena binaria a su representación hexadecimal
static string binaryToHex(string bin) {
    string hex;
    for (size_t i = 0; i < bin.size(); i += 4) {
        // Se divide la string en bloques de 4 bits
        string group = bin.substr(i, 4);
        // Que se convierten en su valor numérico
        int c = BinaryToNum(group);
        // Y luego se obtiene el caracter hexadecimal que corresponde a dicho valor
        hex.push_back(hexChars[c]);
    }
    return hex;
}

// Convierte una cadena binaria a su representación ASCII
static string binaryToAscii(string bin) {
    string ascii;
    for (size_t i = 0; i < bin.size(); i += 8) {
        // Se divide la string en bloques de 8 bits
        string group = bin.substr(i, 8);
        // Que se convierten en su valor numérico
        int c = BinaryToNum(group);
        // Y luego simplemente se concatena ya que cada bloque de 8 bits ya es un caracter ASCII
        ascii.push_back(c);
    }
    return ascii;
}