int foo(real x){
    var int a;
    a = 23;
    if (a == 23){
        a = 10;
    }else{
        a = 19;
    }

    return 2 + a;
}

void main() {
    var int a, b;
    a = 0;
    while(a < 10) {
        b = foo(3.14);
        a = 2 + 2;
    }
}