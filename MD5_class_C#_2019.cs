class MD5_MY {//реализация алгоритма хеширования в классе MD5_MY
    private byte[] update(string input)
    {
        byte[] start = System.Text.Encoding.Default.GetBytes(input);//получаем кодировку по таблице ASCII кодов
        byte[] ap_1 = new byte[start.Length + 2];//добавление 1 и 0,если число %64 = 56
        for(int i = 0; i < start.Length; i++)//переносим данные
        {
            ap_1[i] = start[i];
        }
        ap_1[start.Length] = 128;
        if ((start.Length+1)%64 == 56)
        {
            ap_1[start.Length + 1] = 0;
        }
        int len = ap_1.Length;
        while(len % 64 != 56)//высчитываем необходимую длину
        {
            len++;
        }
        byte[] ap_0 = new byte[len];
        for (int i = 0; i < ap_1.Length; i++)
        {
            ap_0[i] = ap_1[i];
        }
        for (int i = ap_1.Length; i < len; i++)//заполняем нулями
        {
            ap_0[i] = 0;
        }
        return ap_0;

    }
    private uint[] magic =
        {
        0x67452301,
        0xefcdab89,
        0x98badcfe,
        0x10325476
        };//магические константы
    private byte[] digest = new byte[16];//хеш
    private uint F(uint x, uint y, uint z)
    {
        return (((x) & (y)) | ((~x) & (z)));
    }
    private uint G(uint x, uint y, uint z)
    {
        return (((x) & (z)) | ((y) & (~z)));
    }
    private uint H(uint x, uint y, uint z)
    {
        return ((x) ^ (y) ^ (z));
    }
    private uint I(uint x, uint y, uint z)
    {
        return ((y) ^ ((x) | (~z)));
    }
    private uint rotate_left(uint x, int n)
    {
        return (x << n) | (x >> (32 - n));
    }
    private void FF(ref uint a, uint b, uint c, uint d, uint x, uint s, uint ac)
    {
        a = rotate_left(a + F(b, c, d) + x + ac, (int)s) + b;
    }

    private void GG(ref uint a, uint b, uint c, uint d, uint x, uint s, uint ac)
    {
        a = rotate_left(a + G(b, c, d) + x + ac, (int)s) + b;
    }

    private void HH(ref uint a, uint b, uint c, uint d, uint x, uint s, uint ac)
    {
        a = rotate_left(a + H(b, c, d) + x + ac, (int)s) + b;
    }

    private void II(ref uint a, uint b, uint c, uint d, uint x, uint s, uint ac)
    {
        a = rotate_left(a + I(b, c, d) + x + ac, (int)s) + b;
    }
    private void transform(uint[] x) {
        uint a = magic[0], b = magic[1], c = magic[2], d = magic[3];
        FF(ref a, b, c, d, x[0], 7, 0xd76aa478); /* 1 */
        FF(ref d, a, b, c, x[1], 12, 0xe8c7b756); /* 2 */
        FF(ref c, d, a, b, x[2], 17, 0x242070db); /* 3 */
        FF(ref b, c, d, a, x[3], 22, 0xc1bdceee); /* 4 */
        FF(ref a, b, c, d, x[4], 7, 0xf57c0faf); /* 5 */
        FF(ref d, a, b, c, x[5], 12, 0x4787c62a); /* 6 */
        FF(ref c, d, a, b, x[6], 17, 0xa8304613); /* 7 */
        FF(ref b, c, d, a, x[7], 22, 0xfd469501); /* 8 */
        FF(ref a, b, c, d, x[8], 7, 0x698098d8); /* 9 */
        FF(ref d, a, b, c, x[9], 12, 0x8b44f7af); /* 10 */
        FF(ref c, d, a, b, x[10], 17, 0xffff5bb1); /* 11 */
        FF(ref b, c, d, a, x[11], 22, 0x895cd7be); /* 12 */
        FF(ref a, b, c, d, x[12], 7, 0x6b901122); /* 13 */
        FF(ref d, a, b, c, x[13], 12, 0xfd987193); /* 14 */
        FF(ref c, d, a, b, x[14], 17, 0xa679438e); /* 15 */
        FF(ref b, c, d, a, x[15], 22, 0x49b40821); /* 16 */

        /* Round 2 */
        GG(ref a, b, c, d, x[1], 5, 0xf61e2562); /* 17 */
        GG(ref d, a, b, c, x[6], 9, 0xc040b340); /* 18 */
        GG(ref c, d, a, b, x[11], 14, 0x265e5a51); /* 19 */
        GG(ref b, c, d, a, x[0], 20, 0xe9b6c7aa); /* 20 */
        GG(ref a, b, c, d, x[5], 5, 0xd62f105d); /* 21 */
        GG(ref d, a, b, c, x[10], 9, 0x2441453); /* 22 */
        GG(ref c, d, a, b, x[15], 14, 0xd8a1e681); /* 23 */
        GG(ref b, c, d, a, x[4], 20, 0xe7d3fbc8); /* 24 */
        GG(ref a, b, c, d, x[9], 5, 0x21e1cde6); /* 25 */
        GG(ref d, a, b, c, x[14], 9, 0xc33707d6); /* 26 */
        GG(ref c, d, a, b, x[3], 14, 0xf4d50d87); /* 27 */
        GG(ref b, c, d, a, x[8], 20, 0x455a14ed); /* 28 */
        GG(ref a, b, c, d, x[13], 5, 0xa9e3e905); /* 29 */
        GG(ref d, a, b, c, x[2], 9, 0xfcefa3f8); /* 30 */
        GG(ref c, d, a, b, x[7], 14, 0x676f02d9); /* 31 */
        GG(ref b, c, d, a, x[12], 20, 0x8d2a4c8a); /* 32 */

        /* Round 3 */
        HH(ref a, b, c, d, x[5], 4, 0xfffa3942); /* 33 */
        HH(ref d, a, b, c, x[8], 11, 0x8771f681); /* 34 */
        HH(ref c, d, a, b, x[11], 16, 0x6d9d6122); /* 35 */
        HH(ref b, c, d, a, x[14], 23, 0xfde5380c); /* 36 */
        HH(ref a, b, c, d, x[1], 4, 0xa4beea44); /* 37 */
        HH(ref d, a, b, c, x[4], 11, 0x4bdecfa9); /* 38 */
        HH(ref c, d, a, b, x[7], 16, 0xf6bb4b60); /* 39 */
        HH(ref b, c, d, a, x[10], 23, 0xbebfbc70); /* 40 */
        HH(ref a, b, c, d, x[13], 4, 0x289b7ec6); /* 41 */
        HH(ref d, a, b, c, x[0], 11, 0xeaa127fa); /* 42 */
        HH(ref c, d, a, b, x[3], 16, 0xd4ef3085); /* 43 */
        HH(ref b, c, d, a, x[6], 23, 0x4881d05); /* 44 */
        HH(ref a, b, c, d, x[9], 4, 0xd9d4d039); /* 45 */
        HH(ref d, a, b, c, x[12], 11, 0xe6db99e5); /* 46 */
        HH(ref c, d, a, b, x[15], 16, 0x1fa27cf8); /* 47 */
        HH(ref b, c, d, a, x[2], 23, 0xc4ac5665); /* 48 */

        /* Round 4 */
        II(ref a, b, c, d, x[0], 6, 0xf4292244); /* 49 */
        II(ref d, a, b, c, x[7], 10, 0x432aff97); /* 50 */
        II(ref c, d, a, b, x[14], 15, 0xab9423a7); /* 51 */
        II(ref b, c, d, a, x[5], 21, 0xfc93a039); /* 52 */
        II(ref a, b, c, d, x[12], 6, 0x655b59c3); /* 53 */
        II(ref d, a, b, c, x[3], 10, 0x8f0ccc92); /* 54 */
        II(ref c, d, a, b, x[10], 15, 0xffeff47d); /* 55 */
        II(ref b, c, d, a, x[1], 21, 0x85845dd1); /* 56 */
        II(ref a, b, c, d, x[8], 6, 0x6fa87e4f); /* 57 */
        II(ref d, a, b, c, x[15], 10, 0xfe2ce6e0); /* 58 */
        II(ref c, d, a, b, x[6], 15, 0xa3014314); /* 59 */
        II(ref b, c, d, a, x[13], 21, 0x4e0811a1); /* 60 */
        II(ref a, b, c, d, x[4], 6, 0xf7537e82); /* 61 */
        II(ref d, a, b, c, x[11], 10, 0xbd3af235); /* 62 */
        II(ref c, d, a, b, x[2], 15, 0x2ad7d2bb); /* 63 */
        II(ref b, c, d, a, x[9], 21, 0xeb86d391); /* 64 */

        magic[0] += a;
        magic[1] += b;
        magic[2] += c;
        magic[3] += d;
    }
    private void decode(ref uint[] x,byte[] input, int start, bool flag)
    {
        if (flag)//если это 56 байт
        {
            for (int i = start, j = 0; j < 14; i += 4, j++)
            {
                x[j] = System.BitConverter.ToUInt32(input, i);//конвертируем 4 байта в число типа Uint
            }
        }
        else//если больше 56 байт
        {
            for (int i = start, j = 0; i < 64; i += 4, j++)
            {
                x[j] = System.BitConverter.ToUInt32(input, i);//конвертируем 4 байта в число типа Uint
            }
        }
        transform(x);//трансформируем x
    }
public string MD5_FINAL(string input)//общая функция
    {
        System.Text.StringBuilder sBuilder = new System.Text.StringBuilder();
            byte[] start = update(input);//адаптируем строку
            for(int i = 0; i < start.Length; i += 64)//здесь разбиваем строку на 16 слов(по 32 бита)
            {
                bool flag = false;//флаг длины строки
                uint[] x = new uint[16];//массив для трансформации хеша
                if ((start.Length - i) == 56) {//если количество байт 56, то 14 и 15 x это 64 разрядное представление длины строки
                    x[14] = 0;
                    x[15] = 0;
                if ((x[14] + ((uint)start.Length << 3)) < x[14]) {
                    x[15]++;
                }
                x[14] += ((uint)input.Length << 3);//длина строки в виде 64 разрядов, это 32 младшие
                x[15] += (uint)input.Length >> 29;//это 32 старшие
                
                    flag = true;
                }
                decode(ref x, start, i, flag);//декодируем и производим логические операции
            }
            for (int i = 0, j = 0; i < 4; i++, j += 4)//получаем наш хеш из магических констант
            {
                digest[j] = System.Convert.ToByte(magic[i] & 0xFF);
                digest[j + 1] = System.Convert.ToByte((magic[i] >> 8) & 0xFF);
                digest[j + 2] = System.Convert.ToByte((magic[i] >> 16) & 0xFF);
                digest[j + 3] = System.Convert.ToByte((magic[i] >> 24) & 0xFF);
            }
        for (int i = 0; i < 16; i++)//получаем строку в виде 32 символов
        {
            sBuilder.Append(digest[i].ToString("x2"));
        }
        return sBuilder.ToString();
    }
}