#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <QWidget>
#include <fstream> // Include for ifstream
#include <QString>
#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include "trieclass.h"
using namespace std;
std::string filename;
ifstream userInput;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
           "Open File", "", "All Files (*)");

   filename = fileName.toStdString();


}
// you use c samh cherif

void MainWindow::on_pushButton_2_clicked()
{

    QColor white(255, 255, 255);
    ui->textEdit->setTextColor(white);

    userInput.open(filename);


    Trie dictionary;
        string word;
        string temp;

        vector <std::pair<vector<string>,string>> results;

        cout << "Loading data from wordlist.txt" << endl;
        ifstream wordlist("wordlist.txt");
        if (!wordlist.is_open()) {
            cout << "Error opening wordlist.txt file. Please ensure the file wordlist.txt is in the project's path." << endl;

        }

        while (wordlist >> word) {
            dictionary.insert(word);
        }

        /*dictionary.insert("Hello");
        dictionary.insert("world");
        dictionary.insert("programming");
        dictionary.insert("languages");*/


        cout << "Total words in dictionary: " << dictionary.getCount() << endl;



        while (userInput >> word)
        {
                    if (dictionary.search(word))
                    {

                        cout << word << " is spelled correctly." << std::endl;
                    }
                    else
                    {
                        cout << word << " is misspelled." << std::endl;
                        vector<string> suggestions = dictionary.suggestCorrections(word);
                        //getSuggestions(word);

                        pair<vector<string>, string> temp_pair;
                        temp_pair.second = word;
                            cout << "Suggestions for '" << word << "':" << endl;
                        for (const string& suggestion : suggestions) {
                            cout << suggestion << endl;
                            temp_pair.first.push_back(suggestion);
                        }
                        results.push_back(temp_pair);
                    }



        }
        cout << endl;
        cout << "results vector: ";
        for (int i = 0; i < results.size(); i++)
        {
            cout << "word is mis: " << results[i].second << endl;
            cout << "suggestions: " << endl;
            for (int j = 0; j < results[i].first.size(); j++)
            {
                cout << results[i].first[j]<<endl;
            }
        }

}

