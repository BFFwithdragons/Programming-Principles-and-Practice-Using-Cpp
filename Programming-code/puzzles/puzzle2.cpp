int blueTicket(int a, int b, int c) {
    int ab = a + b;
    int ac = a + c;
    int bc = b + c;
    if(ab == 10 || ac == 10 || bc == 10) return 10;
    if((ab) - 10 > 10 && (ab) - (ac) > 10 || (ab) - (bc) > 10) return 5;
    return 0;

}