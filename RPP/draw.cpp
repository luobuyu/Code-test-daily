#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

namespace utils_visualize_drawer
{

    using namespace std;

    class Random
    {
    public:
        using Generator = std::mt19937;

        Random(int seed) : rgen(seed) {}
        Random() : rgen(generateSeed()) {}

        static int generateSeed()
        {
            return static_cast<int>(std::time(nullptr) + std::clock());
        }

        Generator::result_type operator()() { return rgen(); }

        // pick with probability of (numerator / denominator).
        bool isPicked(unsigned numerator, unsigned denominator)
        {
            return ((rgen() % denominator) < numerator);
        }

        // pick from [min, max).
        int pick(int min, int max)
        {
            return ((rgen() % (max - min)) + min);
        }
        // pick from [0, max).
        int pick(int max)
        {
            return (rgen() % max);
        }

    protected:
        Generator rgen;
    };

    struct RandColor
    {
        static constexpr auto ColorCodeChar = "0123456789ABCDEF";
        static constexpr int ColorCodeBase = 16;
        static constexpr int ColorCodeLen = 6;

        void next()
        {
            for (int i = 0; i < ColorCodeLen; ++i)
            {
                int c = r.pick(ColorCodeBase);
                bcolor[i] = ColorCodeChar[c];
                fcolor[i] = ColorCodeChar[(c > (ColorCodeBase / 2)) ? 0 : (ColorCodeBase - 1)]; // (c + ColorCodeBase / 2) % ColorCodeBase
            }
        }

        char fcolor[ColorCodeLen + 1] = {0}; // front color.
        char bcolor[ColorCodeLen + 1] = {0}; // background color.
        Random r;
    };

    struct Drawer
    {
        static constexpr double W = 800;
        static constexpr double H = 600;

        Drawer(string path, double width, double height) : ofs(path)
        {
            begin();
            wx = hx = min(W / width, H / height);
            // wx = W / width;
            // hx = H / height;
        }
        ~Drawer() { end(); }

        void begin()
        {
            ofs << "<!DOCTYPE html>" << endl
                << "<html>" << endl
                << "  <head>" << endl
                << "    <meta charset='utf-8'>" << endl
                << "    <title>SmartMPW Visualization</title>" << endl
                << "  </head>" << endl
                << "  <body>" << endl // style='text-align:center;'
                << "    <svg width='" << W << "' height='" << H << "' viewBox='-50 -50 " << W + 100 << " " << H + 100 << "'>" << endl;
        }
        void end()
        {
            ofs << "    </svg>" << endl
                << "  </body>" << endl
                << "</html>" << endl;
        }

        void rect(double x, double y, double w, double h, bool d, const string &label, const string &fcolor, const string &bcolor)
        {
            if (d)
            {
                swap(w, h);
            }
            x *= wx;
            y *= hx;
            w *= wx;
            h *= hx;
            ofs << "      <rect x='" << x << "' y='" << y << "' width='" << w << "' height='" << h << "' style='fill:#" << bcolor << "; stroke:black; stroke-width:2'/>" << endl
                << "      <text x='" << x + w / 2 << "' y='" << y + h / 2 << "' text-anchor='middle' alignment-baseline='middle' style='fill:#" << fcolor << "'>" << label << "</text>" << endl
                << endl;
        }
        void rect(double x, double y, double w, double h, bool d = false, const string &label = "")
        {
            rc.next();
            rect(x, y, w, h, d, label, rc.fcolor, rc.bcolor);
        }

        void wire(double x, double y, double w, double h, const string &label = "")
        {
            rc.next();
            x *= wx;
            y *= hx;
            w *= wx;
            h *= hx;
            ofs << "      <rect x='" << x << "' y='" << y << "' width='" << w << "' height='" << h << "' style='fill:none"
                << "; stroke:#" << rc.bcolor << "; stroke-width:2; stroke-dasharray:12, 4'/>" << endl
                << "      <text x='" << x + w / 2 << "' y='" << y + h / 2 << "' text-anchor='middle' alignment-baseline='middle' style='fill:#" << rc.fcolor << "'>" << label << "</text>" << endl
                << endl;
        }

        void line(double x1, double y1, double x2, double y2, int layer)
        {
            static vector<int> cutWidth({8, 8, 6});
            static vector<string> cutColor({"red", "blue", "orange"});
            x1 *= wx;
            y1 *= hx;
            x2 *= wx;
            y2 *= hx;
            ofs << "      <line x1='" << x1 << "' y1='" << y1 << "' x2='" << x2 << "' y2='" << y2 << "' stroke-dasharray='12, 4' stroke='" << cutColor[layer] << "' stroke-width='" << cutWidth[layer] << "'/>" << endl
                << endl;
        }

        void circle(double x, double y, double r = 2)
        {
            x *= wx;
            y *= hx;
            ofs << "      <circle cx='" << x << "' cy='" << y << "' r='" << r << "' style='fill-opacity:0; stroke:#000000; stroke-width:2'/>" << endl
                << endl;
        }

        void polygon(const string &polygon_str, const string &label, const string &fcolor, const string &bcolor)
        {
            ofs << "      <polygon points='" << polygon_str << "' style='fill:#" << bcolor << "; stroke:black; stroke-width:1'/>" << endl
                << endl;
        }
        void polygon(const string &polygon_str, const string &label = "")
        {
            rc.next();
            polygon(polygon_str, label, rc.fcolor, rc.bcolor);
        }

        double wx;
        double hx;
        ofstream ofs;
        RandColor rc;
    };
}

using namespace utils_visualize_drawer;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Width, Height;
    read(n, Width, Height);
    Drawer html_drawer("b10.html", Width, Height);
    int x, y, width, height, rotate;
    int w = 0, h = 0;
    for (int i = 1; i <= n; i++)
    {
        read(x, y, width, height, rotate);
        // if (rotate == 1)
        //     height = width;
        html_drawer.rect(x, Height - y - height, width, height, 0, to_string(i));
    }
    return 0;
}