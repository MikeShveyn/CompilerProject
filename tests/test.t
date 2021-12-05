void checkpointers(){

    string y[10];
    y = &x;
    x = &y[5]; 
}