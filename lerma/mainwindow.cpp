#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    ui->loginGB->setStyleSheet("color: black");
    ui->signUpGB->setStyleSheet("color: black");
    ui->usernameLE->setStyleSheet("color: black");
    ui->passwordLE->setStyleSheet("color: black");
    ui->newUserLE->setStyleSheet("color: black");
    ui->emailLE->setStyleSheet("color: black");
    ui->newPasswordLE->setStyleSheet("color: black");
    ui->loginPB->setStyleSheet("color: black");
    ui->signUpPB->setStyleSheet("color: black");
    ui->tittleLBL->setStyleSheet("color: black");

    openFileAction = new QAction("&Open Database",this);
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));
    ui->menubar->addMenu("&File")->addAction(openFileAction);

    QPixmap background(":/Wallpapers/wallpapers/w4.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

   // dbFile.setFileName("lerma.json");
 //   dbFile.open(QIODevice::WriteOnly);
  //  dbFile.close();
}

MainWindow::~MainWindow()
{
    saveChart();
    saveDB();
    delete ui;
}

//Ordenar productos de manera ascendente

void MainWindow::sortAscending()
{
    struct ascendingData{
        inline bool operator () (const Product& p1, const Product p2){
            return (p1.getPrice() < p2.getPrice());
        }
    };

    sort(products.begin(), products.end(), ascendingData());
}

//Ordenar productos de manera descendente

void MainWindow::sortDescending()
{
    struct descendingData{
        inline bool operator () (const Product& p1, const Product p2){
            return (p1.getPrice() > p2.getPrice());
        }
     };

    sort(products.begin(), products.end(), descendingData());
}

void MainWindow::enableLoginPB()
{
    if(ui->usernameLE->text().length() > 0
            && ui->passwordLE->text().length() > 0)
    {
       ui->loginPB->setEnabled(true);
    }
    else
    {
        ui->loginPB->setEnabled(false);
    }
}

void MainWindow::enableSignUpPB()
{
    if((ui->newPasswordLE->text().length() > 0) &&
            (ui->emailLE->text().length() > 0) &&
            (ui->newUserLE->text().length()) > 0)
    {
        ui->signUpPB->setEnabled(true);
    }
    else
    {
        ui->signUpPB->setEnabled(false);
    }
}

void MainWindow::validateUser()
{
    QMessageBox message;
    vector <User>::iterator it;
    QString user = ui->usernameLE->text();
    QString password = ui->passwordLE->text();

    it = find_if(users.begin(), users.end(), [&user, &password](User u) -> bool
    {
        return u.getUsername() == user && u.getPassword() == password;
    }
    );

    if(it == users.end())
    {
        message.setText("Invalid credentials");
        message.setIcon(QMessageBox::Warning);
        message.exec();
    }
    else
    {
        message.setText("Welcome to LERMA " + user);
        userLogged.setUsername(user);
        ui->viewSW->setCurrentIndex(1);
        loadWidgets(6);
        loadRandomWidgets();
        //createGraph();
       /* ProductWidget *uiP = new ProductWidget();
        uiP->LoadProducts(products);
        uiP->ChangeShowProducts("All Departments");
        uiP->showMaximized();
        uiP->show();*/
        message.exec();


    }

}

//Validar mail

bool MainWindow::validateMail()
{
    QMessageBox message;
    QRegularExpression regex("^[a-zA-Z0-9\\._\\+#%\\-]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+(\\.[a-zA-Z0-9]+)*$");
    QString mail = ui->emailLE->text();

    QRegularExpressionMatch match = regex.match(mail);

    if(!match.hasMatch())
    {
        message.setText("Invalid mail");
        message.setIcon(QMessageBox::Warning);
        message.exec();

        return false;
    }
    else
    {
        return true;
    }
}

//Guardar en base de datos

void MainWindow::saveDB()
{
    QJsonObject jsonObj;
    QJsonDocument jsonDoc;

    jsonObj["users"] = dbArray;
    jsonDoc = QJsonDocument(jsonObj);

    dbFile.open(QIODevice::WriteOnly);
    dbFile.write(jsonDoc.toJson());
    dbFile.close();

    jsonObj["products"] = dbArrayProd;
    jsonDoc = QJsonDocument(jsonObj);

    dbFile.open(QIODevice::WriteOnly);
    dbFile.write(jsonDoc.toJson());
    dbFile.close();

}

//Guardar las compras en el array de usuarios

void MainWindow::saveChart()
{
    if (!purchase.empty())
    {
        //Recupero el índice del usuario loggeado
        unsigned int index;

        for(index  = 0 ; index != users.size() ; ++index)
        {
            if(users[index].getUsername() == userLogged.getUsername())
            {
                break;
            }
        }

        QString dateTime = QDateTime::currentDateTime().toString("dd/MM/yy hh:mm:ss");


        QJsonObject purchaseObj;
        QJsonObject userUpdate = dbArray[index].toObject();
        dbArrayP = userUpdate["purchase"].toArray();

        purchaseObj.insert(dateTime, purchase);
        dbArrayP.append(purchaseObj);
        userUpdate["purchase"] = dbArrayP;

        dbArray.removeAt(index);
        dbArray.insert(index, userUpdate);
    }
}

//Cargar desde base de datos

void MainWindow::loadDB()
{
    QJsonObject jsonObj;
    QJsonDocument jsonDoc;
    QByteArray data;

    dbFile.open(QIODevice::ReadOnly);
    data = dbFile.readAll();
    dbFile.close();

    jsonDoc = QJsonDocument::fromJson(data);
    jsonObj = jsonDoc.object();
    dbArray = jsonObj["users"].toArray();
    dbArrayProd = jsonObj["products"].toArray();

    for (int i(0) ; i < dbArray.size(); ++i)
    {
        User u;
        QJsonObject obj = dbArray[i].toObject();
        u.setUsername(obj["name"].toString());
        u.setEmail(obj["email"].toString());
        u.setPassword(obj["password"].toString());
        users.push_back(u);
    }

    //jsonObj = jsonDoc.object();
    //dbArrayProd = jsonObj["products"].toArray();

    for (int i(0); i < dbArrayProd.size(); ++i)
    {
        Product p;
        QJsonObject obj = dbArrayProd[i].toObject();
        p.setId(obj["id"].toString());
        p.setName(obj["name"].toString());
        p.setPrice(obj["price"].toDouble());

        products.push_back(p);
    }

}

//Validar si existe otro usuario ya registrado con el mismo nombre

bool MainWindow::validateNewUser()
{
    QMessageBox message;
    vector <User>::iterator it;
    QString user = ui->newUserLE->text();

    it = find_if(users.begin(), users.end(), [&user](User u) -> bool
    {
        return u.getUsername() == user;
    }
    );

    if(it != users.end())
    {
        message.setText("Invalid username because it's been already registered: "+user);
        message.setIcon(QMessageBox::Warning);
        message.exec();

        return true;
    }


    return false;
}

//Validar si existe otro usuario ya registrado con el mismo correo

bool MainWindow::validateNewEmail()
{
    QMessageBox message;
    vector <User>::iterator it;
    QString email = ui->emailLE->text();

    it = find_if(users.begin(), users.end(), [&email](User u) -> bool
    {
        return u.getEmail() == email;
    }
    );

    if(it != users.end())
    {
        message.setText("Invalid email because it's been already registered: "+email);
        message.setIcon(QMessageBox::Warning);
        message.exec();

        return true;
    }

    return false;
}

//Limpiar los campos del groupbox del Login

void MainWindow::clearLogin()
{
    ui->usernameLE->clear();
    ui->passwordLE->clear();
}

//Limpiar los campos del groupbox del Sign Up

void MainWindow::clearSignUp()
{
    ui->newUserLE->clear();
    ui->emailLE->clear();
    ui->newPasswordLE->clear();
}

//Cargar los productos en la interfáz

void MainWindow::loadWidgets(const int value)
{
    Q_UNUSED(value);

    if ( ui->productsGrid->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->productsGrid->layout()->takeAt(0)) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }

    QString cat="*";
    switch(ui->departmentCB->currentIndex()){
        case 0:{
            cat="*";
            break;
        }
        case 1:{
            cat="AB*";
            break;
        }
        case 2:{
            cat="L*";
            break;
        }
        case 3:{
            cat="E*";
            break;
        }
        case 4:{
            cat="HC*";
            break;
        }
        case 5:{
            cat="D*";
            break;
        }
    }

    QString resultRe("");
    resultRe.append("*");

    if( ui->searchLE->text().size() != 0 ){
        resultRe.append(ui->searchLE->text().toLower());

       }else{

           resultRe.append("[!x]");
       }

       resultRe.append("*");

       QString wildcardSearch = QRegularExpression::wildcardToRegularExpression(resultRe);
       QRegularExpression reSearch(wildcardSearch);

       QString wildcard = QRegularExpression::wildcardToRegularExpression(cat);
       QRegularExpression reDepartament(wildcard);



       //row y c son para determinar la fila y columna.
       //j contar los objetos que tengan match a diferencia de i que cuenta todos
       int row = 0, c = 0, j = 0;
       for(unsigned long long i (0) ; i != products.size() ; ++i)
       {

           QRegularExpressionMatch matchDepartament = reDepartament.match(products[i].getId());
           QRegularExpressionMatch matchSearch = reSearch.match(products[i].getName().toLower());

           if (matchDepartament.hasMatch() && matchSearch.hasMatch())
           {
           //if (products[i].getName().contains(ui->searchLE->text(), Qt::CaseInsensitive) || (matchDepartament.hasMatch() && matchSearch.hasMatch())) {
               ProductWidget* r = new ProductWidget();

               r->setId(products[i].getId());
               r->setName(products[i].getName());

               r->setPrice("\t $" + QString("%2").arg(products[i].getPrice()));
               r->showProduct();

               if(j % 5 == 0 )
               {
                   ++row;
                   c = 0;
               }
               connect(r, SIGNAL(addItem(QString, int)), this, SLOT(addToChart(QString, int)));
               ui->productsGrid->addWidget(r , 1 + row , 1 + c);

               ++c;
               ++j;
           }
       }


}

//Crear el grafo

void MainWindow::createGraph()
{
    QJsonArray purchases;

    for (int j (0) ; j < dbArray.size(); ++j)
    {
        //Se obtiene el usuario a leer en el índice j
        QJsonObject actualUser = dbArray[j].toObject();

        //Se leen las compras del usuario
        purchases = actualUser["purchase"].toArray();

        //Se recorren las compras del usuario
        for (int i(0); i < purchases.size() ; ++i)
        {
            recuperarProductos(purchases[i].toObject());
            combineNodeProd();

            //Borrar la lista de compras
            for (int i(purchaseList.size()); i >= 0 ; --i)
            {
                purchaseList.removeAt(i);
            }
        }
    }

    //Imprimimos el grafo
    graph.printData();
}

void MainWindow::recuperarProductos(QJsonObject value)
{
    //Obtener nombre del campo nombrado con la fecha y hora
    QString field = value.keys().last();
    QJsonArray items = value[field].toArray();

    //Se guarda la lista de compras en su campo ID
    for (int i (0) ; i < items.size() ; ++i)
    {
        QJsonObject item = items[i].toObject();
        purchaseList.push_back(item["id"].toString());
    }

}

void MainWindow::combineNodeProd()
{
    //Recorremos la lista de compras
    for (int i(0) ; i < purchaseList.size() ; ++i)
    {

        for (int j(i+1) ; j < purchaseList.size() ; ++j)
        {
            string value = purchaseList[i].toStdString();
            string value2 = purchaseList[j].toStdString();

            if(graph.isEdge(value, value2))
            {
                graph.createEdge(value, value2, graph.getCost(value, value2) + 1);
            }
            else
            {
                graph.createEdge(value, value2, 1);
            }
        }

    }
}

//Agrega los productos recomendados en la cola de prioridad

void MainWindow::createRecommendedWidgets()
{

    //Elimino todos los widgets dentro del SA de los artículos recomendados
    if ( ui->recommendedGrid->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->recommendedGrid->layout()->takeAt(0)) != NULL)
        {
            delete item->widget();
            delete item;
        }
    }

    //Limpiamos o eleminamos cada elemento de la cola
    if (!cola.empty())
    {
        while (!cola.empty())
        {
            cola.pop();
        }

    }

    //Busco los 5 primeros productos para obtener su información y agregarlos a la cola
    for ( unsigned int i (0) ; (i < recommendedProducts.size()) && (i < 5) ; ++i )
    {
        for ( unsigned int k (0) ; k < products.size() ; ++k )
        {
            if ( products[k].getId() == recommendedProducts[i].getId() )
            {
                Product p;

                p.setId(products[k].getId());
                p.setName(products[k].getName());
                p.setPrice(products[k].getPrice());
                p.setWeight(recommendedProducts[i].getWeight());

                //Introduzco el producto en la cola
                cola.push(p);
            }
        }
    }

    if (!cola.empty())
    {
        loadRecommendedWidgets();
    }

}

//Genera los productos aleatorios

void MainWindow::loadRandomWidgets()
{
    int row = 0, c = 0, j = 0;

    for (int i (0) ; i < 5 ; ++i)
    {
        //genero número aleatorio entre 0 y 49
        std::uniform_int_distribution<int> distribution(0, 49);
        int aleato = distribution(*QRandomGenerator::global());

        ProductWidget *product = new ProductWidget( this );

        product->setId(products[aleato].getId());
        product->setName(products[aleato].getName());
        product->setPrice("\t $" + QString("%2").arg(products[aleato].getPrice()));
        product->showProduct();

        if( j % 5 == 0 )
        {
            ++row;
            c = 0;
        }

        connect( product, SIGNAL(addItem(QString, int)), this, SLOT(addToChart(QString, int)));
        ui->recommendedGrid->addWidget( product , 1 + row , 1 + c );
        ++c;
        ++j;
    }


}

//Se obtienen los productos recomendados

void MainWindow::getRecomendations(QString value)
{

    string addedCartProductId = value.toLocal8Bit().constData();
    bool f = 0;
    qDebug () << "-------------------";

    for(unsigned int i (0) ; i < products.size() ; ++i )
    {
        string anyOtherProduct = products[i].getId().toLocal8Bit().constData();
        f = 0;
        if(graph.isEdge(addedCartProductId, anyOtherProduct))
        {

            double cost = graph.getCost(addedCartProductId, anyOtherProduct);
            Product p;
            p.setId(products[i].getId());
            p.setWeight(cost);

            if (recommendedProducts.size() > 0)
            {
                // Buscar algun producto recomendado en el array de recomendados si esta repetido
                for (unsigned int j(0) ; j != recommendedProducts.size() ; ++j)
                {
                    //Si encuentra el producto repetido
                    if (products[i].getId() == recommendedProducts[j].getId())
                    {
                        //Si lo encuentra, compara si el que encontraste tiene menor peso de la arista
                        //con el que agregaste, si es de menor peso lo reemplaza con el existente en el array
                        //y queda el que tenga mayor peso en el arreglo
                        if (cost >= recommendedProducts[j].getWeight())
                        {
                            recommendedProducts.at(j).setWeight(cost);
                            f = 1;
                            //break;
                        }
                    }
                }

                //Si no encuentra ninguno repetido entonces lo agrego directamente al array de recomendados
                if (f == 0)
                {
                    recommendedProducts.push_back(p);
                }

            }
            else
            {
                recommendedProducts.push_back(p);
            }

        }
    }


    qDebug () << "\n Productos Ordenados de mayor a menor \n";

    struct descendingData {
        inline bool operator () (const Product& p1, const Product& p2){
            return (p1.getWeight() > p2.getWeight());
        }
     };

    sort(recommendedProducts.begin(), recommendedProducts.end(), descendingData());
    for(unsigned int k (0) ; k < recommendedProducts.size(); ++k)
    {
        QString id = recommendedProducts[k].getId();
        qDebug () << "p "<< k+1 << ": "<<id.toLocal8Bit().constData()<<" w: "<<recommendedProducts[k].getWeight();
    }
    qDebug () << "-------------------";

}

//Carga los productos recomendados a widgets

void MainWindow::loadRecommendedWidgets()
{
    int row = 0, c = 0, j = 0;

    //Verifico si la cola no está vacía
    if (!cola.empty())
    {
        //Itero sobre el elemento que se encuentra enfrente o el primero
        while (!cola.empty())
        {
            ProductWidget* product;
            product = new ProductWidget( this );

            product->setId(cola.front().getId());
            product->setName(cola.front().getName());

            product->setPrice("\t $" + QString("%2").arg(cola.front().getPrice()));
            product->showProduct();

            qDebug() <<"P: "<<cola.front().getId();

            if ( j % 5 == 0 )
            {
                ++row;
                c = 0;
            }

            connect(product, SIGNAL(addItem(QString, int)), this, SLOT(addToChart(QString, int)));
            ui->recommendedGrid->addWidget( product , 1 + row , 1 + c );
            ++c;
            ++j;

            //Elimino el producto de enfrente
            cola.pop();
        }

    }

}

//Inicio de Sesión

void MainWindow::on_usernameLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    enableLoginPB();
}

void MainWindow::on_passwordLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    enableLoginPB();
}

//Registro de nuevo usuario

void MainWindow::on_newUserLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    enableSignUpPB();
}

void MainWindow::on_emailLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    enableSignUpPB();
}

void MainWindow::on_newPasswordLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    enableSignUpPB();
}

void MainWindow::on_signUpPB_clicked()
{

    QJsonObject jsonObj;

    QMessageBox message;
    User u;

    if(!validateNewUser())
    {
        if(validateMail())
        {
            if(!validateNewEmail())
            {
                u.setUsername(ui->newUserLE->text());
                u.setEmail(ui->emailLE->text());
                u.setPassword(ui->newPasswordLE->text());

                users.push_back(u);
                message.setText("New User Created");
                message.exec();

                clearSignUp();

                jsonObj["name"] = u.getUsername();
                jsonObj["email"] = u.getEmail();
                jsonObj["password"] = u.getPassword();
                dbArray.append(jsonObj);
            }
            else
            {
                clearSignUp();
            }
        }
        else
        {
            clearSignUp();
        }
    }
    else
    {
        clearSignUp();
    }
}

void MainWindow::openFile()
{
    QString name;
    name = QFileDialog::getOpenFileName(this,
                                        "Select Database",
                                        "",
                                        "JSON files(*.json)");

    if (name.length() > 0)
    {
        dbFile.setFileName(name);
        ui->loginGB->setEnabled(true);
        ui->signUpGB->setEnabled(true);
        loadDB();
        createGraph();
    }
}

//Volver a cargar los productos al vector

void MainWindow::reloadProducts()
{
    //borra todo el vector products
    foreach (Product p, products) {
        products.pop_back();
    }

    //vuelve a llenar el vector products con los datos originales leidos de la bd
    for(int i(0);i<dbArrayProd.size();++i){
        Product p;
        QJsonObject obj = dbArrayProd[i].toObject();
        p.setId(obj["id"].toString());
        p.setName(obj["name"].toString());
        p.setPrice(obj["price"].toDouble());
        products.push_back(p);
    }
}

//Evento del botón iniciar sesión

void MainWindow::on_loginPB_clicked()
{
    validateUser();
    clearLogin();
}

//Evento del cambio de departamento

void MainWindow::on_departmentCB_currentIndexChanged(int index)
{
    ui->searchLE->clear();
    ui->sortCB->setCurrentIndex(0);
    loadWidgets(index);
}

//Método de ordenar de mayor a menor y viceversa

void MainWindow::on_sortCB_currentIndexChanged(int index)
{
    switch(index){
        case 0:{
            reloadProducts();
            break;
        }
        case 1:{
            sortAscending();
            break;
        }
        case 2:{
            sortDescending();
            break;
        }
    }
    loadWidgets(index);
}

//Añadir al carrito

void MainWindow::addToChart(QString item, int amount)
{

    getRecomendations(item.toLocal8Bit().constData());
    createRecommendedWidgets();

    QJsonObject stackObject;

    stackObject.insert("id", QJsonValue::fromVariant(item));
    stackObject.insert("units", QJsonValue::fromVariant(amount));

    purchase.push_back(stackObject);



}

//Evento de la búsqueda de los productos

void MainWindow::on_searchLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    //ui->searchLE->clearFocus();
    loadWidgets(6);
}

