extern "C" float func_0057AE68(int, float, float) throw() __attribute__((const));
extern "C" float func_0057B0A0(float a, float b, float t, float lo, float hi) {
    float result = a;
    b = b - result;
    b = func_0057AE68(1, b - lo, hi - lo) + lo;
    b *= t;
    result += b;
    return result;
}
