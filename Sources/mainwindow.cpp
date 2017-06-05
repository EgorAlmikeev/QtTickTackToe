#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    CreateWidgets();
    CreateSizePolicy();
    CreateMapping();
    CreateObjectNames();

    setWindowTitle("TickTackToe");

    x_window_size = 500;
    y_window_size = 600;

    resize(x_window_size, y_window_size);

    setMaximumSize(x_window_size, y_window_size);
    setMinimumSize(x_window_size, y_window_size);

    first_player = 1;
    second_player = 2;
    current_player = first_player;

    x_board_size = 3;
    y_board_size = 3;
    InitializeGameBoard();
}

MainWindow::~MainWindow()
{}

void MainWindow::slotGameButtonPressed(int button_number)
{
    ChangeBoard(button_number);
    ChangeButtonColor(button_number);
    CheckThisPlayerForWin();
}

void MainWindow::CreateWidgets()
{
    main_layout = new QGridLayout;
    central_widget = new QWidget(this);
    central_widget->setLayout(main_layout);
    setCentralWidget(central_widget);

    player_screen = new QLabel("PLAYER : 1");
    player_screen->setAlignment(Qt::AlignCenter);
    player_screen->setFont(QFont("Courier New", 40));

    button_0 = new QPushButton();
    button_1 = new QPushButton();
    button_2 = new QPushButton();
    button_3 = new QPushButton();
    button_4 = new QPushButton();
    button_5 = new QPushButton();
    button_6 = new QPushButton();
    button_7 = new QPushButton();
    button_8 = new QPushButton();

    main_layout->addWidget(player_screen, 0, 0, 1, 3);

    main_layout->addWidget(button_0, 1, 0);
    main_layout->addWidget(button_1, 1, 1);
    main_layout->addWidget(button_2, 1, 2);
    main_layout->addWidget(button_3, 2, 0);
    main_layout->addWidget(button_4, 2, 1);
    main_layout->addWidget(button_5, 2, 2);
    main_layout->addWidget(button_6, 3, 0);
    main_layout->addWidget(button_7, 3, 1);
    main_layout->addWidget(button_8, 3, 2);
}

void MainWindow::CreateSizePolicy()
{
    player_screen->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    button_0->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_4->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_5->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_6->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_7->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    button_8->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

void MainWindow::CreateMapping()
{
    game_button_mapper = new QSignalMapper(this);

    connect(button_0, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_1, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_2, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_3, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_4, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_5, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_6, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_7, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(button_8, SIGNAL(clicked()), game_button_mapper, SLOT(map()), Qt::UniqueConnection);

    game_button_mapper->setMapping(button_0, 0);
    game_button_mapper->setMapping(button_1, 1);
    game_button_mapper->setMapping(button_2, 2);
    game_button_mapper->setMapping(button_3, 3);
    game_button_mapper->setMapping(button_4, 4);
    game_button_mapper->setMapping(button_5, 5);
    game_button_mapper->setMapping(button_6, 6);
    game_button_mapper->setMapping(button_7, 7);
    game_button_mapper->setMapping(button_8, 8);

    connect(game_button_mapper, SIGNAL(mapped(int)), this, SLOT(slotGameButtonPressed(int)), Qt::UniqueConnection);
}

void MainWindow::CreateObjectNames()
{}

void MainWindow::ChangeBoard(int button_number)
{
    switch(button_number)
    {
    case 0 : game_board[0][0] = current_player; break;
    case 1 : game_board[0][1] = current_player; break;
    case 2 : game_board[0][2] = current_player; break;
    case 3 : game_board[1][0] = current_player; break;
    case 4 : game_board[1][1] = current_player; break;
    case 5 : game_board[1][2] = current_player; break;
    case 6 : game_board[2][0] = current_player; break;
    case 7 : game_board[2][1] = current_player; break;
    case 8 : game_board[2][2] = current_player; break;
    }
}

void MainWindow::ChangeButtonColor(int button_number)
{
    QPushButton *current_button;

    switch(button_number)
    {
    case 0 :
    {
        current_button = button_0;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 1 :
    {
        current_button = button_1;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 2 :
    {
        current_button = button_2;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 3 :
    {
        current_button = button_3;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 4 :
    {
        current_button = button_4;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 5 :
    {
        current_button = button_5;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 6 :
    {
        current_button = button_6;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 7 :
    {
        current_button = button_7;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    case 8 :
    {
        current_button = button_8;
        if(current_player == first_player)
            FirstPlayerColor(current_button);
        else
            SecondPlayerColor(current_button);
        break;
    }
    }

    current_button->setEnabled(false);
}

void MainWindow::FirstPlayerColor(QPushButton *current_button)
{
    current_button->setStyleSheet(
                "border: 2px solid #d15252;"
                "background-color: #d15252;"
                "color: #2736db;"
                "font-size: 200pt;"
                "font-family: Arial;"
                );
    current_button->setText("×");
}

void MainWindow::SecondPlayerColor(QPushButton *current_button)
{
    current_button->setStyleSheet(
                "border: 2px solid #2736db;"
                "background-color: #2736db;"
                "color: #d15252;"
                "font-size: 200pt;"
//                "font-family: Arial;"
                );
    current_button->setText("⦁");
}

void MainWindow::ChangePlayer()
{
    if(current_player == first_player)
    {
        current_player = second_player;
        player_screen->setText("PLAYER : 2");
    }
    else
    {
        current_player = first_player;
        player_screen->setText("PLAYER : 1");
    }
}

void MainWindow::CheckThisPlayerForWin()
{
    if(game_board[0][0] == current_player && game_board[0][1] == current_player && game_board[0][2] == current_player)
        PlayerWin(current_player);
    else if(game_board[1][0] == current_player && game_board[1][1] == current_player && game_board[1][2] == current_player)
        PlayerWin(current_player);
    else if(game_board[2][0] == current_player && game_board[2][1] == current_player && game_board[2][2] == current_player)
        PlayerWin(current_player);

    else if(game_board[0][0] == current_player && game_board[1][0] == current_player && game_board[2][0] == current_player)
        PlayerWin(current_player);
    else if(game_board[0][1] == current_player && game_board[1][1] == current_player && game_board[2][1] == current_player)
        PlayerWin(current_player);
    else if(game_board[0][2] == current_player && game_board[1][2] == current_player && game_board[2][2] == current_player)
        PlayerWin(current_player);

    else if(game_board[0][0] == current_player && game_board[1][1] == current_player && game_board[2][2] == current_player)
        PlayerWin(current_player);
    else if(game_board[0][2] == current_player && game_board[1][1] == current_player && game_board[2][0] == current_player)
        PlayerWin(current_player);

    else if(
            game_board[0][0] != 0 && game_board[0][1] != 0 && game_board[0][2] != 0 &&
            game_board[1][0] != 0 && game_board[1][1] != 0 && game_board[1][2] != 0 &&
            game_board[2][0] != 0 && game_board[2][1] != 0 && game_board[2][2] != 0
            )
        PlayerWin(0);
    else
        ChangePlayer();
}

void MainWindow::PlayerWin(short player_number)
{
    if(player_number == first_player)
        player_screen->setText("WINNER : PLAYER 1");
    else if(player_number == second_player)
        player_screen->setText("WINNER : PLAYER 2");
    else
        player_screen->setText("DRAW");

    SetAllButtonsDisable();
}

void MainWindow::Restart()
{
    InitializeGameBoard();
    ClearButtons();
    SetAllButtonsEnable();
}

void MainWindow::InitializeGameBoard()
{
    for(short i = 0; i < y_board_size; ++i)
        for(short j = 0; j < x_board_size; ++j)
            game_board[i][j] = 0;
}

void MainWindow::SetAllButtonsEnable()
{
    if(!button_0->isEnabled())
        button_0->setEnabled(true);
    if(!button_1->isEnabled())
        button_1->setEnabled(true);
    if(!button_2->isEnabled())
        button_2->setEnabled(true);
    if(!button_3->isEnabled())
        button_3->setEnabled(true);
    if(!button_4->isEnabled())
        button_4->setEnabled(true);
    if(!button_5->isEnabled())
        button_5->setEnabled(true);
    if(!button_6->isEnabled())
        button_6->setEnabled(true);
    if(!button_7->isEnabled())
        button_7->setEnabled(true);
    if(!button_8->isEnabled())
        button_8->setEnabled(true);
}

void MainWindow::SetAllButtonsDisable()
{
    if(button_0->isEnabled())
        button_0->setEnabled(false);
    if(button_1->isEnabled())
        button_1->setEnabled(false);
    if(button_2->isEnabled())
        button_2->setEnabled(false);
    if(button_3->isEnabled())
        button_3->setEnabled(false);
    if(button_4->isEnabled())
        button_4->setEnabled(false);
    if(button_5->isEnabled())
        button_5->setEnabled(false);
    if(button_6->isEnabled())
        button_6->setEnabled(false);
    if(button_7->isEnabled())
        button_7->setEnabled(false);
    if(button_8->isEnabled())
        button_8->setEnabled(false);
}

void MainWindow::ClearButtons()
{}
