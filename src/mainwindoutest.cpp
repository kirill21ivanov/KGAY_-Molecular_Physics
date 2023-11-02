#include "mainwindoutest.h"
#include "ui_mainwindoutest.h"

MainWindouTest::MainWindouTest(const QString &name, const QString &group, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindouTest)
{
    ui->setupUi(this);
    this->ui->part_name->setText(name);
    names = name;
    groups = group;
    this->ui->part_group->setText(group);
    timer = new QTimer(this);
    timeRemaining = QTime(0, 20, 0);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimerDisplay()));
    timer->start(1000);
}

void MainWindouTest::on_exit_clicked() {
    this->hide();
    a = new MainWindowFin(names, groups, userScore);
    a->setWindowState(Qt::WindowNoState);
    a->show();
}

MainWindouTest::~MainWindouTest()
{
    delete ui;
}

void MainWindouTest::updateTimerDisplay() {
    timeRemaining = timeRemaining.addSecs(-1);
    if (timeRemaining == QTime(0, 0)) {
        on_exit_clicked();
        timer->stop();
    }
    this->ui->timer->setText(timeRemaining.toString("mm:ss"));
}

void MainWindouTest::shuffleOptions(QString &option1, QString &option2, QString &option3) {
    QStringList optionsList;
    optionsList << option1 << option2 << option3;
    std::shuffle(optionsList.begin(), optionsList.end(), std::mt19937(std::random_device()()));
    option1 = optionsList[0];
    option2 = optionsList[1];
    option3 = optionsList[2];
}

void MainWindouTest::on_but_1_clicked() {
    if (!question1Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Газ считается идеальным, если можно пренебречь");
        QString option1 = "взаимодействием молекул";
        QString option2 = "массой молекул ";
        QString option3 = "скоростью молекул";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);        
        question1Answered = false;
    }
}

void MainWindouTest::on_but_2_clicked() {
    if (!question2Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);

        this->ui->win_start->setText("Давление идеального газа зависит от");

        QString option1 = "силы притяжения молекул";
        QString option2 = "кинетической энергии молекул ";
        QString option3 = "потенциальной энергии";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);

        question2Answered = false;
    }
}

void MainWindouTest::on_but_3_clicked() {

    if (!question3Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Из сосуда выпустили половину газа. Чтобы давление оставшегося газа увеличилось в 3 раза, надо его абсолютную температуру");

        QString option1 = " увеличить в 9 раза";
        QString option2 = " увеличить в 6 раза";
        QString option3 = " уменьшить в 6 раз";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question3Answered = false;
    }
}
void MainWindouTest::on_but_4_clicked() {

    if (!question4Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText(" В баллоне объемом 2 л находиться 0,2 моля кислорода. Плотность кислорода равна ");

        QString option1 = "5,4";
        QString option2 = "3,2";
        QString option3 = "4,0";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question4Answered = false;
    }
}
void MainWindouTest::on_but_5_clicked() {

    if (!question5Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Наиболее вероятная скорость молекул увеличилась в 3 раза. Температура идеального газа при этом увеличилась в");

        QString option1 = "3";
        QString option2 = "9";
        QString option3 = "√8";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question5Answered = false;
    }
}
void MainWindouTest::on_but_6_clicked() {

    if (!question6Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Идеальный газ не совершает работу в процессе");

        QString option1 = " изобарическом";
        QString option2 = " изохорическом";
        QString option3 = " изотермическом";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question6Answered = false;
    }
}
void MainWindouTest::on_but_7_clicked() {

    if (!question7Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Явление диффузии можно наблюдать");

        QString option1 = "только в газах и жидкостях";
        QString option2 = "в газах, жидкостях и твердых телах ";
        QString option3 = "только в твердых телах";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question7Answered = false;
    }
}
void MainWindouTest::on_but_8_clicked() {

    if (!question8Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Число молекул в одном моле кислорода приблизительно равно");

        QString option1 = "12∙10^23";
        QString option2 = "6∙10^23 ";
        QString option3 = "16∙10^23";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question8Answered = false;
    }
}
void MainWindouTest::on_but_9_clicked() {

    if (!question9Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Единица измерения молярной массы");

        QString option1 = "кг";
        QString option2 = "кг/моль ";
        QString option3 = "г";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question9Answered = false;
    }
}
void MainWindouTest::on_but_10_clicked() {

    if (!question10Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("При уменьшении абсолютной температуры в 8 раз средняя кинетическая энергия идеального газа");

        QString option1 = "не изменится;";
        QString option2 = "уменьшится в 8 раз; ";
        QString option3 = "увеличится в 8 раз; ";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question10Answered = false;
    }
}
void MainWindouTest::on_but_11_clicked() {

    if (!question11Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("При нагревании идеального газа его абсолютная температура увеличилась в 2 раза. Как изменилась при этом средняя кинетическая энергия теплового ");

        QString option1 = "увеличилась в 4 раза";
        QString option2 = "увеличилась в 2 раза";
        QString option3 = "увеличилась в 16 раз";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question11Answered = false;
    }
}
void MainWindouTest::on_but_12_clicked() {

    if (!question12Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Явление диффузии в жидкостях объясняется тем, что молекулы жидкостей");

        QString option1 = "притягиваются друг к другу";
        QString option2 = "могут хаотично перемещаться по объёму";
        QString option3 = "отталкиваются друг от друга";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question12Answered = false;
    }
}
void MainWindouTest::on_but_13_clicked() {

    if (!question13Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Какова температура кипения воды при нормальном атмосферном давлении по абсолютной шкале температур");

        QString option1 = "173 К";
        QString option2 = "373 К";
        QString option3 = "273 К";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question13Answered = false;
    }
}
void MainWindouTest::on_but_14_clicked() {

    if (!question14Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Укажите, в каком из ответов наиболее полно представлены основные положения молекулярно-кинетической теории строения вещества:");

        QString option1 = "вещество состоит из элементарных частиц и они взаимно превращаются друг в друга";
        QString option2 = "вещество состоит из мельчайших частиц и между ними действуют силы";
        QString option3 = "вещество состоит из маленьких частей и они заполняют пространство ";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question14Answered = false;
    }
}
void MainWindouTest::on_but_15_clicked() {

    if (!question15Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Средняя кинетическая энергия теплового движения молекул зависит");

        QString option1 = "от агрегатного состояния вещества";
        QString option2 = "зависит от температуры ";
        QString option3 = "зависит от давления";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question15Answered = false;
    }
}
void MainWindouTest::on_but_16_clicked() {

    if (!question16Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Средняя кинетическая энергия теплового движения молекул не зависит");

        QString option1 = "от агрегатного состояния вещества";
        QString option2 = "от массы молекул ";
        QString option3 = "от температуры";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question16Answered = false;
    }
}
void MainWindouTest::on_but_17_clicked() {

    if (!question17Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText(" От какой из приведенных ниже величин, характеризующих молекулы, зависит давление идеального газа");

        QString option1 = " силы притяжения между молекулами";
        QString option2 = " кинетической энергии молекул";
        QString option3 = " силы отталкивания между молекулами";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question17Answered = false;
    }
}
void MainWindouTest::on_but_18_clicked() {

    if (!question18Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Как изменится средняя кинетическая энергия теплового движения молекул идеального газа в некотором процессе, если концентрацию молекул уменьшить в 10 раз, а температуру увеличить в 2 раза");

        QString option1 = "уменьшится в 5 раз ";
        QString option2 = " увеличится в 2 раза  ";
        QString option3 = "увеличится в 5 раз ";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question18Answered = false;
    }
}
void MainWindouTest::on_but_19_clicked() {

    if (!question19Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Раздел физики, который изучает физические свойства тел на основе рассмотрения их молекулярного строения");

        QString option1 = "квантовая физика";
        QString option2 = "молекулярная физика и термодинамика";
        QString option3 = "Астрофизика";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question19Answered = false;
    }
}
void MainWindouTest::on_but_20_clicked() {

    if (!question20Answered) {
        ui->awin_1->setEnabled(true);
        ui->awin_2->setEnabled(true);
        ui->awin_3->setEnabled(true);
        this->ui->win_start->setText("Как изменяется температура газа при его адиабатическом сжатии");

        QString option1 = "Не изменяется ";
        QString option2 = "повышается";
        QString option3 = "понижается";
        QStringList options;
        options << option1 << option2 << option3;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(options.begin(), options.end(), g);
        this->ui->awin_1->setText(options[0]);
        this->ui->awin_2->setText(options[1]);
        this->ui->awin_3->setText(options[2]);
        correctAnswer = option2;
        connect(ui->awin_1, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_2, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        connect(ui->awin_3, &QPushButton::clicked, this, &MainWindouTest::checkAnswer);
        question20Answered = false;
    }
}

void MainWindouTest::checkAnswer() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    QString selectedAnswer = clickedButton->text();
    if (clickedButton) {
        if (selectedAnswer == "взаимодействием молекул" || selectedAnswer == "массой молекул " || selectedAnswer == "скоростью молекул") {
            ui->but_1->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_1->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question1Answered = true;
                if(question1 == false){
                    userScore += 1;
                }
                question1 = true;
                qDebug() << "Начислен балл 1";
            } else {

            }
        } else if (selectedAnswer == "силы притяжения молекул" || selectedAnswer == "кинетической энергии молекул " || selectedAnswer == "потенциальной энергии") {
            ui->but_2->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_2->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question2Answered = true;
                if(question2 == false){
                    userScore += 1;
                }
                question2 = true;
                qDebug() << "Начислен балл 2";
            } else {

            }
        } else if (selectedAnswer == " увеличить в 9 раза" || selectedAnswer == " увеличить в 6 раза" || selectedAnswer == " уменьшить в 6 раз") {
            ui->but_3->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_3->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question3Answered = true;
                if(question3 == false){
                    userScore += 1;
                }
                question3 = true;
                qDebug() << "Начислен балл 3";
            } else {

            }
        }else if (selectedAnswer == "5,4" || selectedAnswer == "3,2" || selectedAnswer == "4,0") {
            ui->but_4->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_4->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question4Answered = true;
                if(question4 == false){
                    userScore += 1;
                }
                question4 = true;
                qDebug() << "Начислен балл 4";
            } else {

            }
        }else if (selectedAnswer == "3" || selectedAnswer == "9" || selectedAnswer == "√8") {
            ui->but_5->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_5->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question5Answered = true;
                if(question5 == false){
                    userScore += 1;
                }
                question5 = true;
                qDebug() << "Начислен балл 5";
            } else {

            }
        }else if (selectedAnswer == " изобарическом" || selectedAnswer == " изохорическом" || selectedAnswer == " изотермическом") {
            ui->but_6->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_6->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question6Answered = true;
                if(question6 == false){
                    userScore += 1;
                }
                question6 = true;
                qDebug() << "Начислен балл 6";
            } else {

            }
        }else if (selectedAnswer == "только в газах и жидкостях" || selectedAnswer == "в газах, жидкостях и твердых телах " || selectedAnswer == "только в твердых телах") {
            ui->but_7->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_7->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question7Answered = true;
                if(question7 == false){
                    userScore += 1;
                }
                question7 = true;
                qDebug() << "Начислен балл 7";
            } else {

            }
        }else if (selectedAnswer == "12∙10^23" || selectedAnswer == "6∙10^23 " || selectedAnswer == "16∙10^23") {
            ui->but_8->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_8->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question8Answered = true;
                if(question8 == false){
                    userScore += 1;
                }
                question8 = true;
                qDebug() << "Начислен балл 8";
            } else {

            }
        }else if (selectedAnswer == "кг" || selectedAnswer == "г" || selectedAnswer == "кг/моль ") {
            ui->but_9->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_9->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question9Answered = true;
                if(question9 == false){
                    userScore += 1;
                }
                question9 = true;
                qDebug() << "Начислен балл 9";
            } else {

            }
        }else if (selectedAnswer == "не изменится;" || selectedAnswer == "уменьшится в 8 раз; " || selectedAnswer == "увеличится в 8 раз; ") {
            ui->but_10->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_10->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question10Answered = true;
                if(question10 == false){
                    userScore += 1;
                }
                question10 = true;
                qDebug() << "Начислен балл 10";
            } else {

            }
        }else if (selectedAnswer == "увеличилась в 4 раза" || selectedAnswer == "увеличилась в 2 раза" || selectedAnswer == "увеличилась в 16 раза") {
            ui->but_11->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_11->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question11Answered = true;
                if(question11 == false){
                    userScore += 1;
                }
                question11 = true;
                qDebug() << "Начислен балл 11";
            } else {

            }
        }else if (selectedAnswer == "притягиваются друг к другу" || selectedAnswer == "могут хаотично перемещаться по объёму" || selectedAnswer == "отталкиваются друг от друга") {
            ui->but_12->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_12->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question12Answered = true;
                if(question12 == false){
                    userScore += 1;
                }
                question12 = true;
                qDebug() << "Начислен балл 12";
            } else {

            }
        }else if (selectedAnswer == "173 К" || selectedAnswer == "373 К" || selectedAnswer == "273 К") {
            ui->but_13->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_13->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question13Answered = true;
                if(question13 == false){
                    userScore += 1;
                }
                question13 = true;
                qDebug() << "Начислен балл 13";
            } else {

            }
        }else if (selectedAnswer == "вещество состоит из элементарных частиц и они взаимно превращаются друг в друга" || selectedAnswer == "вещество состоит из мельчайших частиц и между ними действуют силы" || selectedAnswer == "вещество состоит из маленьких частей и они заполняют пространство ") {
            ui->but_14->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_14->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question14Answered = true;
                if(question14 == false){
                    userScore += 1;
                }
                question14 = true;
                qDebug() << "Начислен балл 14";
            } else {

            }
        }else if (selectedAnswer == "от агрегатного состояния вещества" || selectedAnswer == "зависит от температуры " || selectedAnswer == "зависит от давления") {
            ui->but_15->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_15->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question15Answered = true;
                if(question15 == false){
                    userScore += 1;
                }
                question15 = true;
                qDebug() << "Начислен балл 15";
            } else {

            }
        }else if (selectedAnswer == "от агрегатного состояния вещества" || selectedAnswer == "от массы молекул " || selectedAnswer == "от температуры") {
            ui->but_16->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_16->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question16Answered = true;
                if(question16 == false){
                    userScore += 1;
                }
                question16 = true;
                qDebug() << "Начислен балл 16";
            } else {

            }
        }else if (selectedAnswer == " силы притяжения между молекулами" || selectedAnswer == " кинетической энергии молекул" || selectedAnswer == " силы отталкивания между молекулами") {
            ui->but_17->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_17->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question17Answered = true;
                if(question17 == false){
                    userScore += 1;
                }
                question17 = true;
                qDebug() << "Начислен балл 17";
            } else {

            }
        }else if (selectedAnswer == "уменьшится в 5 раз " || selectedAnswer == " увеличится в 2 раза  " || selectedAnswer == "увеличится в 5 раза ") {
            ui->but_18->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_18->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question18Answered = true;
                if(question18 == false){
                    userScore += 1;
                }
                question18 = true;
                qDebug() << "Начислен балл 18";
            } else {

            }
        }else if (selectedAnswer == "квантовая физика" || selectedAnswer == "молекулярная физика и термодинамика" || selectedAnswer == "Астрофизика") {
            ui->but_19->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_19->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question19Answered = true;
                if(question19 == false){
                    userScore += 1;
                }
                question19 = true;
                qDebug() << "Начислен балл 19";
            } else {

            }
        }else if (selectedAnswer == "Не изменяется " || selectedAnswer == "повышается" || selectedAnswer == "понижается") {
            ui->but_20->setEnabled(false);
            ui->awin_1->setEnabled(false);
            ui->awin_2->setEnabled(false);
            ui->awin_3->setEnabled(false);
            ui->but_20->setStyleSheet("background-color: gray; border-radius: 10px;");
            if (selectedAnswer == correctAnswer) {
                question20Answered = true;
                if(question20 == false){
                    userScore += 1;
                }
                question20 = true;
                qDebug() << "Начислен балл 20";
            } else {

            }
        }

        if (question1Answered && question2Answered && question3Answered) {
            qDebug() << "Итог тестирвования: " << userScore;
        }
    }
}

