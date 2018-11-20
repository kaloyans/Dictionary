//---------------------------------------------------------------------------

#pragma hdrstop

#include "DictionaryClass.h"
#include "string.h"
#include "iostream.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


Dictionary::Dictionary()
{
        for(int i=0; i < 100; i++){
                TableFromFile[i].Bulgarian[i]=0;
                TableFromFile[i].English[i]=0;
        }

        TableEnd = 0;
}

int Dictionary::Add(int positionInsert, TableContent * row)
{
        if(positionInsert > 99)
                return -404; // error - no space in table to insert

        // search - to check the result if it has it or not

        if(positionInsert < TableEnd-1)
        {
                int j= positionInsert+1,
                    i = positionInsert;

                for(; i<= TableEnd ; i++, j++){
                          strcpy(TableFromFile[j].Bulgarian, TableFromFile[i].Bulgarian);
                          strcpy(TableFromFile[j].English, TableFromFile[i].English);
                }

                strcpy(TableFromFile[positionInsert].Bulgarian, row->Bulgarian);
                strcpy(TableFromFile[positionInsert].English, row->English );

                TableEnd++;
                return 0;// successfully recorded entry

        }
        else if(positionInsert == TableEnd-1)
        {
                strcpy(TableFromFile[TableEnd].Bulgarian, row->Bulgarian);
                strcpy(TableFromFile[TableEnd].English, row->English);

                TableEnd++;
                return 0;// successfully recorded entry
        }

        return -1; // unsuccessfully entered entry
}

int Dictionary::Delete(int positionDelete)
{
          if(positionInsert < 0)
                return -404; // error - no space in table to insert

          // if(Search()) -- to check if there is one or not
          
          if(positionInsert < TableEnd-1)
          {
                int j= positionInsert+1,
                    i = positionInsert;

                for(; i<= TableEnd ; i++, j++){
                          strcpy(TableFromFile[i].Bulgarian, TableFromFile[j].Bulgarian);
                          strcpy(TableFromFile[i].English, TableFromFile[j].English);
                }

                // delete the last dropped item
                TableFromFile[i].Bulgarian[0] = 0;
                TableFromFile[i].English[0] = 0;

                TableEnd--;
                return 0;// successfully recorded entry
          }
          else if(positionInsert == TableEnd-1)
          {
                TableFromFile[TableEnd].Bulgarian[0] = 0;
                TableFromFile[TableEnd].English[0] = 0;

                TableEnd--;
                return 0;// successfully recorded entry
          }

          return -1; // unsuccessfully entered entry
}

void Dictionary::printContentOfTable()
{
        int i=0;

        cout << " ----- Content of table -----" << endl;
        for(; i<100 ;i++){
                //cout << " Bulgarian word: " << TableFromFile[i].Bulgarian << " // English word: "
        }
}
