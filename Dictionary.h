//---------------------------------------------------------------------------



struct TableContent{
        char Bulgarian[100];
        char English[100];
};

class Dictionary{
        TableContent TableFromFile[100]; // tablica sus sudurjanieto na prevodite ot tekstoviq fail
        int TableEnd;

        public:
        Dictionary(); // constructor

        int Add(int positionInsert, TableContent * row);
        int Delete(int positionDelete);
        void printContentOfTable();

};

#ifndef DictionaryClassH
#define DictionaryClassH
//---------------------------------------------------------------------------
#endif
