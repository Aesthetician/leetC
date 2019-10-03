class Solution {
public:
    string numberToWords(int num) {
        vector<string> unit{"", " Thousand ", " Million ", " Billion "};
        vector<string> ten{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> one{"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        int pos = 0;
        string res; 
        if (num == 0) return "Zero";
        while (num > 0) {
            /*
            edge case: 1000, -> One Thousand +" " 
            normal case: 1010
            */
            if (num % 1000 > 0) res = ToWords(num % 1000, ten, one) + unit[pos] + res;
            num = num / 1000;
            pos++;
        }
        if (res[res.size()-1] == ' ') return res.substr(0, res.size()-1);
        return res;
    }
    
    string ToWords(int num, const vector<string>& ten, const vector<string>& one) {
        if (num < 20) {
            return one[num];
        } else if (num >= 20 && num < 100) {
            if (num % 10 > 0) return ten[num/10-2] + " " + ToWords(num % 10, ten, one);
            else return ten[num/10-2];
        } else {//1000 > num >= 100
            if (num % 100 > 0) return one[num/100] + " Hundred" + " " + ToWords(num % 100, ten, one);
            else return one[num/100] + " Hundred";
        } 
    }
};
