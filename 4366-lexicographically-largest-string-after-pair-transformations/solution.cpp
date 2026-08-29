class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> result;
        result.reserve(nums.size());
        for (int n : nums) {
            string s = "";
            int count = n;
            char c = 'a';
            while (c) {
                if (c == 'z') {
                    s.append(count, 'z');
                    break;
                }
                if (count % 2) s += c;
                count /= 2;
                c++;
            }
            sort(s.rbegin(), s.rend());
            result.push_back(s);
        }
        return result;
    }
};

//q2 non ne ho idea questo ho capito il trucco invece.
//le aaaa sono singoli numeri 1 e li devo raggruppare come se fossere numeri binari esempio due 1 1 fa 10 eccetra
//poi quando ho inve numero binario metto la lettera corrispondente se quella cifra è 1 se no no
//a = 1 b = 10 c = 100 e via cosi
// mi sembrava logico ma adesso provo con la dp... ah probabilmente colpa della z in effetti
