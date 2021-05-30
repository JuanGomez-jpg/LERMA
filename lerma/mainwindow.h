#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include <QRegularExpression>
#include <QAction>
#include <QFile>
#include "user.h"
#include "productwidget.h"
#include "product.h"
#include <QValidator>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QGraphicsScene>
#include <QDateTime>
#include "graph.h"
#include <queue>
#include <QRandomGenerator>
#include <QtGui>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sortAscending();
    void sortDescending();

private slots:
    void on_usernameLE_textChanged(const QString &arg1);

    void on_passwordLE_textChanged(const QString &arg1);

    void on_newUserLE_textChanged(const QString &arg1);

    void on_emailLE_textChanged(const QString &arg1);

    void on_newPasswordLE_textChanged(const QString &arg1);

    void on_loginPB_clicked();

    void on_signUpPB_clicked();

    void openFile();

    void reloadProducts();

    void on_departmentCB_currentIndexChanged(int index);

    void on_sortCB_currentIndexChanged(int index);

    void addToChart(QString item, int amount);

    void on_searchLE_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    vector <User> users;
    vector <Product> products;

    QAction* openFileAction;
    QFile dbFile;
    QJsonArray dbArray;
    QJsonArray dbArrayProd;
    QJsonArray dbArrayP;

    QJsonArray purchase;
    User userLogged;

    Graph<string> graph;

    QStringList purchaseList;

    vector<Product> recommendedProducts;

    queue<Product> cola;

    void enableLoginPB();
    void enableSignUpPB();
    void validateUser();
    bool validateMail();
    void saveDB();
    void saveChart();
    void loadDB();
    bool validateNewUser();
    bool validateNewEmail();
    void clearLogin();
    void clearSignUp();
    void loadWidgets(const int value);

    void createGraph();
    void recuperarProductos(QJsonObject value);
    void combineNodeProd();

    void loadRandomWidgets();
    void getRecomendations(QString value);
    void createRecommendedWidgets();
    void loadRecommendedWidgets();

};
#endif // MAINWINDOW_H
