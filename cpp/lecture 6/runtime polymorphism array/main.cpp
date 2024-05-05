#include"shape.cpp"

char get_shapechoice() {
    char choice;
    cout<<"which shape you want : "<<endl;
    cout<<"enter c/r/s: ";
    cin>> choice;
    return choice;
}

shape * get_shape(char shapechoice) {
    shape *sptr = NULL;
    switch(shapechoice) {
        case 'c' : 
            sptr = new circle;
            break;
        case 'r' :
            sptr = new rectangle;
            break;
        case 's' :
            sptr = new sphere;
            break;
        default :
            cout<<" invalid choice "<<endl;
    }
    return sptr;
}

int main() {

    shape * shapeptr_arr[4];
    char shapechoice;

    for(int i = 0; i < 4; i++) {
        shapechoice = get_shapechoice();

        // shape *sptr = get_shape(shapechoice);
        // shapeptr_arr = sptr;

        shapeptr_arr[i] = get_shape(shapechoice);

        shapeptr_arr[i] -> accept();

        shapeptr_arr[i] -> calculate_area();
    }

    for(shape *s: shapeptr_arr) {
        s -> display();
    }

    return 0;
}