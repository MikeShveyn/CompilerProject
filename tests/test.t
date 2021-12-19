void main() {
    var int x=1;
    var real f;
    var char a=3;
    a = x * 3 + 5;
    while(x>a) {
        a = x * 3 + 100;
        if(x>a) {
            a = x * 3 + 100;
        }
        else {
            x = a * 3 + 100;
        }
    }
}