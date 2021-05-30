/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *viewSW;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QGroupBox *signUpGB;
    QGridLayout *gridLayout_4;
    QLineEdit *newUserLE;
    QLineEdit *emailLE;
    QLineEdit *newPasswordLE;
    QPushButton *signUpPB;
    QGroupBox *loginGB;
    QGridLayout *gridLayout_3;
    QPushButton *loginPB;
    QLineEdit *usernameLE;
    QLineEdit *passwordLE;
    QLabel *tittleLBL;
    QWidget *page_2;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollAreaRecommended;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_9;
    QGridLayout *recommendedGrid;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_8;
    QGridLayout *productsGrid;
    QGroupBox *departmentsGB;
    QGridLayout *gridLayout_5;
    QLineEdit *searchLE;
    QComboBox *departmentCB;
    QComboBox *sortCB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1031, 634);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(1902, 1080));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        viewSW = new QStackedWidget(centralwidget);
        viewSW->setObjectName(QString::fromUtf8("viewSW"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        viewSW->setFont(font);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        signUpGB = new QGroupBox(page);
        signUpGB->setObjectName(QString::fromUtf8("signUpGB"));
        signUpGB->setEnabled(false);
        signUpGB->setMaximumSize(QSize(200, 200));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        signUpGB->setFont(font1);
        signUpGB->setStyleSheet(QString::fromUtf8("font:rgb(255, 255, 255)"));
        signUpGB->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(signUpGB);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        newUserLE = new QLineEdit(signUpGB);
        newUserLE->setObjectName(QString::fromUtf8("newUserLE"));
        newUserLE->setFont(font1);

        gridLayout_4->addWidget(newUserLE, 0, 0, 1, 1);

        emailLE = new QLineEdit(signUpGB);
        emailLE->setObjectName(QString::fromUtf8("emailLE"));
        emailLE->setFont(font1);

        gridLayout_4->addWidget(emailLE, 1, 0, 1, 1);

        newPasswordLE = new QLineEdit(signUpGB);
        newPasswordLE->setObjectName(QString::fromUtf8("newPasswordLE"));
        newPasswordLE->setFont(font1);
        newPasswordLE->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(newPasswordLE, 2, 0, 1, 1);

        signUpPB = new QPushButton(signUpGB);
        signUpPB->setObjectName(QString::fromUtf8("signUpPB"));
        signUpPB->setEnabled(false);
        signUpPB->setFont(font1);

        gridLayout_4->addWidget(signUpPB, 3, 0, 1, 1);


        gridLayout_2->addWidget(signUpGB, 3, 0, 1, 1);

        loginGB = new QGroupBox(page);
        loginGB->setObjectName(QString::fromUtf8("loginGB"));
        loginGB->setEnabled(false);
        loginGB->setMaximumSize(QSize(200, 200));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gill Sans MT"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        loginGB->setFont(font2);
        loginGB->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(loginGB);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        loginPB = new QPushButton(loginGB);
        loginPB->setObjectName(QString::fromUtf8("loginPB"));
        loginPB->setEnabled(false);
        loginPB->setFont(font2);

        gridLayout_3->addWidget(loginPB, 2, 0, 1, 1);

        usernameLE = new QLineEdit(loginGB);
        usernameLE->setObjectName(QString::fromUtf8("usernameLE"));
        usernameLE->setFont(font2);

        gridLayout_3->addWidget(usernameLE, 0, 0, 1, 1);

        passwordLE = new QLineEdit(loginGB);
        passwordLE->setObjectName(QString::fromUtf8("passwordLE"));
        passwordLE->setFont(font2);
        passwordLE->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(passwordLE, 1, 0, 1, 1);


        gridLayout_2->addWidget(loginGB, 2, 0, 1, 1);

        tittleLBL = new QLabel(page);
        tittleLBL->setObjectName(QString::fromUtf8("tittleLBL"));
        tittleLBL->setMaximumSize(QSize(400, 70));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font3.setPointSize(31);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        tittleLBL->setFont(font3);
        tittleLBL->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(tittleLBL, 1, 0, 1, 1);

        viewSW->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_6 = new QGridLayout(page_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        scrollAreaRecommended = new QScrollArea(page_2);
        scrollAreaRecommended->setObjectName(QString::fromUtf8("scrollAreaRecommended"));
        scrollAreaRecommended->setMaximumSize(QSize(16777215, 230));
        scrollAreaRecommended->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 985, 188));
        gridLayout_9 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        recommendedGrid = new QGridLayout();
        recommendedGrid->setObjectName(QString::fromUtf8("recommendedGrid"));

        gridLayout_9->addLayout(recommendedGrid, 0, 0, 1, 1);

        scrollAreaRecommended->setWidget(scrollAreaWidgetContents_2);

        gridLayout_6->addWidget(scrollAreaRecommended, 2, 0, 1, 1);

        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Montserrat"));
        font4.setPointSize(8);
        scrollArea->setFont(font4);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 985, 189));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        productsGrid = new QGridLayout();
        productsGrid->setSpacing(7);
        productsGrid->setObjectName(QString::fromUtf8("productsGrid"));

        gridLayout_8->addLayout(productsGrid, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_6->addWidget(scrollArea, 1, 0, 1, 1);

        departmentsGB = new QGroupBox(page_2);
        departmentsGB->setObjectName(QString::fromUtf8("departmentsGB"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Montserrat"));
        font5.setPointSize(11);
        departmentsGB->setFont(font5);
        departmentsGB->setAlignment(Qt::AlignCenter);
        gridLayout_5 = new QGridLayout(departmentsGB);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        searchLE = new QLineEdit(departmentsGB);
        searchLE->setObjectName(QString::fromUtf8("searchLE"));

        gridLayout_5->addWidget(searchLE, 2, 0, 1, 1);

        departmentCB = new QComboBox(departmentsGB);
        departmentCB->addItem(QString());
        departmentCB->addItem(QString());
        departmentCB->addItem(QString());
        departmentCB->addItem(QString());
        departmentCB->addItem(QString());
        departmentCB->addItem(QString());
        departmentCB->setObjectName(QString::fromUtf8("departmentCB"));

        gridLayout_5->addWidget(departmentCB, 0, 0, 1, 1);

        sortCB = new QComboBox(departmentsGB);
        sortCB->addItem(QString());
        sortCB->addItem(QString());
        sortCB->addItem(QString());
        sortCB->setObjectName(QString::fromUtf8("sortCB"));

        gridLayout_5->addWidget(sortCB, 1, 0, 1, 1);


        gridLayout_6->addWidget(departmentsGB, 0, 0, 1, 1);

        viewSW->addWidget(page_2);

        gridLayout->addWidget(viewSW, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1031, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        viewSW->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LERMA", nullptr));
        signUpGB->setTitle(QApplication::translate("MainWindow", "Sign Up", nullptr));
        newUserLE->setPlaceholderText(QApplication::translate("MainWindow", "User", nullptr));
        emailLE->setPlaceholderText(QApplication::translate("MainWindow", "Email", nullptr));
        newPasswordLE->setPlaceholderText(QApplication::translate("MainWindow", "Password", nullptr));
        signUpPB->setText(QApplication::translate("MainWindow", "Sign Up", nullptr));
        loginGB->setTitle(QApplication::translate("MainWindow", "Login", nullptr));
        loginPB->setText(QApplication::translate("MainWindow", "Login", nullptr));
        usernameLE->setPlaceholderText(QApplication::translate("MainWindow", "User", nullptr));
        passwordLE->setPlaceholderText(QApplication::translate("MainWindow", "Password", nullptr));
        tittleLBL->setText(QApplication::translate("MainWindow", "LERMA", nullptr));
        departmentsGB->setTitle(QApplication::translate("MainWindow", "Departments", nullptr));
        searchLE->setPlaceholderText(QApplication::translate("MainWindow", "Product Name", nullptr));
        departmentCB->setItemText(0, QApplication::translate("MainWindow", "All Departments", nullptr));
        departmentCB->setItemText(1, QApplication::translate("MainWindow", "Food & Drinks", nullptr));
        departmentCB->setItemText(2, QApplication::translate("MainWindow", "Books", nullptr));
        departmentCB->setItemText(3, QApplication::translate("MainWindow", "Electronics", nullptr));
        departmentCB->setItemText(4, QApplication::translate("MainWindow", "Home & Kitchen", nullptr));
        departmentCB->setItemText(5, QApplication::translate("MainWindow", "Sport & Outdoors", nullptr));

        sortCB->setItemText(0, QApplication::translate("MainWindow", "Sort...", nullptr));
        sortCB->setItemText(1, QApplication::translate("MainWindow", "Ascending", nullptr));
        sortCB->setItemText(2, QApplication::translate("MainWindow", "Descending", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
