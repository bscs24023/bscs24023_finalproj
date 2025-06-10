#include "Mystr.h"



    String:: String()
    {
        len = 0;
        cap = 1;
        Cs = new char[1];
        Cs[0] = '\0';
        
    } 

    int String :: length(const char *p) const
    {
        int len = 0;
        while (p[len] != '\0') 
        {
            len++;
        }
        return len;
    }

    String :: String(const char *p)
    {
        len = length(p);
        cap = len + 1;
        Cs = new char[cap];
        for (int i = 0; i < len; i++) 
        {
            Cs[i] = p[i];
        }
        Cs[len] = '\0';
    }
    
    void String:: copy(const char *p)
    {
        len = length(p);
        cap = len + 1;
        Cs = new char[cap];
        for (int i = 0; i < len; i++) 
        {
            Cs[i] = p[i];
        }
        Cs[len] = '\0';
    }

    String :: String(int n, char c)
    {
        len = n;
        cap = n + 1;
        Cs = new char [cap];

        for (int i = 0; i < n; i++)
        {
            Cs[i] = c;
        }
        Cs[n] = '\0';
    }

    String String::itos(int num)

    {
        int len1 = 0;
        int temp = num;
        
        if (temp == 0) 
        {
            len1 = 1;
        }
        else 
        {
            while (temp) 
            { 
                len1++; 
                temp = temp / 10;
            }
        }
        int cap1 = len1 + 1;
        char* str = new char[cap1];
        str[len1] = '\0';
    
        for (int i = len1 - 1; i >= 0; i--) 
        {
            str[i] = 48 + (num % 10);
            num /= 10;
        }
    
        String result(str);
        delete[] str; 
        return result;
    }

    int String::stoi(const String s)
    {
        int num = 0;
        for (int i = 0; i < s.len; i++)
        {  
            num = num * 10 + (s.Cs[i] - 48);
        }
        return num;
    }

    String::String(int num)
    {
        String(itos(num));
    } 

    void String :: replace_first(char c)
    {
        if (len > 0) 
        {
            Cs[0] = c;
        }
    }

    String:: String(const String &s)
    {
        len = s.len;
        cap = s.cap;
        Cs = new char[s.cap];
        for (int i = 0; i < len; i++) 
        {
            Cs[i] = s.Cs[i];
        }
        Cs[len] = '\0';
    }

    void String :: print() const 
    { 
        cout << Cs << endl; 
    }

    char String::operator[](int i) const

    {
        if (i < 0 || i >= len) 
        {
            cout << "Error";
        }
        return Cs[i];
    }

    char& String ::operator[](int i) 
    {
        if (i < 0 || i >= len) 
        {
            cout << "Error";            
        }
        return Cs[i];
    }
    

    void String :: insert_at(int i, char ch) 
    {
        if (i < 0 || i > len) 
        {
            return; 
        }

        if (len + 1 >= cap) 
        {
            cap = cap * 2;  
            char* temp = new char[cap];

            for (int j = 0; j < len; j++) 
            {
                temp[j] = Cs[j];
            }
            
            delete[] Cs;
            Cs = temp;
        }

        for (int j = len; j > i; j--) 
        {
            Cs[j] = Cs[j - 1];
        }

        Cs[i] = ch;
        len++;
        Cs[len] = '\0'; 
    }

    void String :: insert_at(int i, const String &sub) 
    {
        if (i < 0 || i > len) 
        {
            return; 
        }

        int len2 = len + sub.len;

        if (len2 >= cap) 
        {
            cap = len2 + 1;  
            char* temp = new char[cap];

            for (int j = 0; j < len; j++) 
            {
                temp[j] = Cs[j];
            }

            delete[] Cs;
            Cs = temp;
        }

        for (int j = len - 1; j >= i; j--) 
        {
            Cs[j + sub.len] = Cs[j];
        }

        for (int j = 0; j < sub.len; j++) 
        {
            Cs[i + j] = sub.Cs[j];
        }

        len = len2;
        Cs[len] = '\0'; 
    }
    bool String :: is_equal(const String& M) 
    {
        if (len != M.len)
        {
            return false;
        }

        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] != M.Cs[i]) 
            {
                return false;
            }
        }
        return true; 
    }

    bool String :: is_less(const String& M) 
    {
        int min;
        if (len < M.len) 
        {
            min = len;
        }
        else 
        {
            min = M.len;
        }

        for (int i = 0; i < min; i++) 
        {
            if (Cs[i] < M.Cs[i]) 
            {
                return true;
            }
            if (Cs[i] > M.Cs[i]) 
            {
                return false; 
            }
        }
        return len < M.len; 
    }

    bool String :: is_greater(const String& M) 
    {
        int min;
        if (len < M.len) 
        {
            min = len;
        }
        else 
        {
            min = M.len;
        }
       
        for (int i = 0; i < min; i++) 
        {
            if (Cs[i] > M.Cs[i])
            {
                return true;
            }  
            if (Cs[i] < M.Cs[i]) 
            {
                return false;
            } 
        }
        return len > M.len; 
    }
    String& String::trim()
    {
        int s = 0;
        int e = len - 1;

        while (s < len && (Cs[s] == ' ' || Cs[s] == '\t' || Cs[s] == '\n'))
        {
            s++;
        }

        while (e >= s && (Cs[e] == ' ' || Cs[e] == '\t' || Cs[e] == '\n'))
        {
            e--;
        }

        int len2 = e - s + 1;
        int cap2 = len2+1;

        char *temp = new char[cap2];

        for (int i = 0; i < len2; i++)
        {
            temp[i] = Cs[s + i];
        }
        temp[len2] = '\0';

        delete[] Cs;
        Cs = temp;
        len = len2;
        cap = cap2;
        
        return *this;
    }
    String* String::split(char delim, int &count) const
    {
        count = 1;  
        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] == delim) 
            {
                count++;
            }
        }

        String* parts = new String[count]; 

        int s = 0;
        int no_part = 0;
        for (int i = 0; i <= len; i++) 
        {
            if (Cs[i] == delim || Cs[i] == '\0') 
            {
                int len2 = i - s;
                int cap2 = len2 + 1;

                parts[no_part] = String(); 
                parts[no_part].Cs = new char[cap2];  
                parts[no_part].len = len2;
                parts[no_part].cap = cap2;

                for (int j = 0; j < len2; j++) 
                {
                    parts[no_part].Cs[j] = Cs[s + j];  
                }
                parts[no_part].Cs[len2] = '\0';

                no_part++;  
                s = i + 1; 
            }
        }
        return parts;
    }

    String* String:: tokenize(const char *delim, int &count) const 
    {
        count = 1;

        for (int i = 0; i < len; i++) 
        {
            for (int j = 0; delim[j] != '\0'; j++) 
            {
                if (Cs[i] == delim[j]) 
                {
                    count++;  
                }
            }
        }

        String* parts = new String[count]; 

        int s = 0;
        int no_part = 0;
        for (int i = 0; i <= len; i++) 
        {
            bool flag = false;

            for (int j = 0; delim[j] != '\0'; j++) 
            {
                if (Cs[i] == delim[j] || Cs[i] == '\0') 
                {
                    flag = true;
                    break;
                }
            }

            if (flag || Cs[i] == '\0') 
            {
                int len2 = i - s;
                int cap2 = len2 + 1;

                if (len2 > 0)  
                {
                    parts[no_part] = String();
                    parts[no_part].Cs = new char[cap2];  
                    parts[no_part].len = len2;
                    parts[no_part].cap = cap2;

                    for (int j = 0; j < len2; j++) 
                    {
                        parts[no_part].Cs[j] = Cs[s + j];  
                    }
                    parts[no_part].Cs[len2] = '\0';

                    no_part++;  
                }
                s = i + 1;  
            }
        }
        count = no_part;  
        return parts;
    }
    String String::concat(const String& s2) const
    {
        int len2 = len + s2.len;
        int cap2 = len2 + 1;
        
        char* temp = new char[cap2]; 

        for (int i = 0; i < len; i++) 
        {
            temp[i] = Cs[i];  
        }
        for (int i = 0; i < s2.len; i++) 
        {
            temp[len + i] = s2.Cs[i];  
        }
        temp[len2] = '\0';  

        String result(temp);
        delete[] temp;  
        return result;
    }
    int String :: find_first(char ch) const 
    {
        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] == ch) 
            {
                return i;
            }
        }
        return -1;  
    }

    int String :: find_first(const String &sub) const 
    {
        int len2 = sub.len;

        for (int i = 0; i <= len - len2; i++) 
        {
            bool flag = true;
            for (int j = 0; j < len2; j++) 
            {
                if (Cs[i + j] != sub.Cs[j]) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag) 
            {
                return i;
            }
        }
        return -1;
    }

    int String :: find_last(char ch) const 
    {
        for (int i = len - 1; i >= 0; i--) 
        {
            if (Cs[i] == ch) 
            {
                return i;
            }
        }
        return -1;
    }

    int String :: find_last(const String &sub) const 
    {
        int len2 = sub.len;

        for (int i = len - len2; i >= 0; i--) 
        {
            bool flag = true;
            for (int j = 0; j < len2; j++) 
            {
                if (Cs[i + j] != sub.Cs[j]) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag) 
            {
                return i;
            }
        }
        return -1;
    }

    int* String :: find_all(char ch, int &count) const 
    {
        count = 0;

        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] == ch) 
            {
                count++;
            }
        }

        int* temp = new int[count];
        int idx = 0;

        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] == ch) 
            {
                temp[idx++] = i;
            }
        }

        return temp;
    }

    int* String :: find_all(const String &sub, int &count) const 
    {
        count = 0;
        int len2 = sub.len;

        for (int i = 0; i <= len - len2; i++) 
        {
            bool flag = true;
            for (int j = 0; j < len2; j++) 
            {
                if (Cs[i + j] != sub.Cs[j]) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag) 
            {
                count++;
            }
        }

        int* temp = new int[count];
        int idx = 0;

        for (int i = 0; i <= len - len2; i++) 
        {
            bool flag = true;
            for (int j = 0; j < len2; j++) 
            {
                if (Cs[i + j] != sub.Cs[j]) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag) 
            {
                temp[idx] = i;
                idx++;
            }
        }

        return temp;
    }

    void String :: remove_at(int i) 
    {
        if (i < 0 || i >= len) 
        {
            return; 
        }

        for (int j = i; j < len - 1; j++) 
        {
            Cs[j] = Cs[j + 1]; 
        }
        
        Cs[len - 1] = '\0'; 
        len--; 
    }

    
    void String :: remove_first(char ch) 
    {
        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] == ch) 
            {
                for (int j = i; j < len - 1; j++)
                {
                    Cs[j] = Cs[j + 1];
                }
                Cs[len - 1] = '\0';
                len--;
                cap--;
                return; 
            }
        }
    }

    void String :: remove_last(char ch) 
    {
        int idx = -1;
        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] == ch) 
            {
                idx = i;
            }
        }
        if (idx != -1) 
        {
            for (int j = idx; j < len - 1; j++)
            {
                Cs[j] = Cs[j + 1];
            }
            Cs[len - 1] = '\0';
            len--;
            cap--;
        }
    }

    void String :: remove_all(char ch) 
    {
        int ct = 0;
        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] == ch) 
            {
                ct++;
            }
        }
    
        char* temp = new char[len - ct + 1]; 
        int idx = 0;
        
        for (int i = 0; i < len; i++) 
        {
            if (Cs[i] != ch) 
            {
                temp[idx] = Cs[i];
                idx++;
            }
        }
        
        temp[idx] = '\0';
        
        delete[] Cs;
        Cs = temp;
        len = len - ct;
        cap = len + 1;
    }
    void String :: clear() 
    {
        delete[] Cs;
        len = 0;       
        cap = 1;           
        Cs = new char[1];
        Cs[0] = '\0';
    }

    void String :: to_upper()
    {
        for (int i = 0; i < len; i++)
        {
            if (Cs[i] >= 'a' && Cs[i] <= 'z')
            {
                Cs[i] = Cs[i] - 32;
            }
        }
    }
    
    void String :: to_lower()
    {
        for (int i = 0; i < len; i++)
        {
            if (Cs[i] >= 'A' && Cs[i] <= 'Z')
            {
                Cs[i] = Cs[i] + 32;
            }
        }
    }

    String::~String()
    { 
        delete[] Cs; 
    }

    istream& operator>>(istream& in, String& string)
    {
        char temp[1000];
        
        in.getline(temp, 1000);
        
        string.copy(temp);
        
        return in;
    }
    
    ostream& operator<<(ostream& out, const String& string)
    {
        out << string.Cs << endl; 
        
        return out;
    }
    
    