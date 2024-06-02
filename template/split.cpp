vector<string> split(string &str, char delim)
{
    stringstream ss(str);
    vector<string> ret;
    string s;
    while (getline(ss, s, delim))
        ret.emplace_back(s);
    return ret;
}