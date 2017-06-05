#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGridLayout;
class QLabel;
class QPushButton;
class QSignalMapper;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots :

    void slotGameButtonPressed(int button_number);

private :

    //widgets things
    int x_window_size;
    int y_window_size;

    short x_board_size;
    short y_board_size;

    //game things
    short game_board[3][3];

    short current_player;
    short first_player;
    short second_player;

    //widgets functions
    void CreateWidgets();
    void CreateSizePolicy();
    void CreateObjectNames();
    void CreateMapping();

    void SetAllButtonsDisable();
    void SetAllButtonsEnable();

    void ClearButtons();

    //game process functions
    void CheckThisPlayerForWin();
    void ChangeBoard(int button_number);
    void ChangePlayer();
    void PlayerWin(short player_number);

    void Restart();
    void InitializeGameBoard();

    //button color functions
    void ChangeButtonColor(int button_number);
    void FirstPlayerColor(QPushButton *current_button);
    void SecondPlayerColor(QPushButton *current_button);

    //base elements
    QWidget *central_widget;
    QGridLayout *main_layout;
    QSignalMapper *game_button_mapper;

    //game elements
    QLabel *player_screen;

    QPushButton *button_0;
    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_3;
    QPushButton *button_4;
    QPushButton *button_5;
    QPushButton *button_6;
    QPushButton *button_7;
    QPushButton *button_8;
};

#endif // MAINWINDOW_H
