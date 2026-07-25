/// \file dialogaddcity.h
/// \brief Deklaration des Dialogs DialogAddCity.

#ifndef DIALOGADDCITY_H
#define DIALOGADDCITY_H

#include <QDialog>

#include "city.h"

namespace Ui {
class DialogAddCity;
}

/**
 * @brief Dialog, der Name und Koordinaten fuer eine neue Stadt abfragt.
 *
 * Der Benutzer gibt Name, X- und Y-Koordinate ein. Ueber getCity()
 * wird daraus eine neue City erzeugt.
 */
class DialogAddCity : public QDialog
{
    Q_OBJECT

public:
    /// @brief Erzeugt den Dialog.
    /// @param parent Elternfenster
    explicit DialogAddCity(QWidget *parent = nullptr);

    /// @brief Gibt den Dialog frei.
    ~DialogAddCity();

    /**
     * @brief Wertet die Eingaben aus und erzeugt eine neue Stadt.
     * @return Zeiger auf die neu erzeugte City
     */
    City* getCity();

private:
    Ui::DialogAddCity *ui;
};

#endif // DIALOGADDCITY_H
