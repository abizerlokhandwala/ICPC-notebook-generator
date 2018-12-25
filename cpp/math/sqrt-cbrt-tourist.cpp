ll my_sqrt(ll x) {
    assert(x > 0);
    ll y = (ll) (sqrtl((ld) x) + 0.5);
    while (y * y < x)
        y++;
    while (y * y > x)
        y--;
    if (y * y == x)
        return y;
    return -1;
}
ll my_cbrt(ll x) {
    assert(x > 0);
    ll y = (ll) (powl((ld) x, 1.0 / 3.0) + 0.5);
    while (y * y * y < x)
        y++;
    while (y * y * y > x)
        y--;
    if (y * y * y == x)
        return y;
    return -1;
}