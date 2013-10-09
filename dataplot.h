/*
 *    This application is visualizes data from imu-utils over tcp
 *
 *    Copyright (C) 2013 Simon Stürz (stuerz.simon@gmail.com)
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef DATAPLOT_H
#define DATAPLOT_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QTabWidget>
#include <QTimer>
#include <QVector>
#include <QVector3D>

#include <qcustomplot.h>
#include <visualization.h>

class DataPlot : public QWidget
{
    Q_OBJECT
public:
    explicit DataPlot(QWidget *parent = 0);
    void updateSensorData(const QVector3D &accData, const QVector3D &gyrData, const QVector3D &magData);
    void updateAngleData(const QVector3D &angleData);

    QWidget *createAccPlot();
    QWidget *createGyrPlot();
    QWidget *createMagPlot();
    QWidget *createAnglePlot();

private:
    QTabWidget *m_tabWidget;
    Visualization *m_visualization;

    // plot data
    QCustomPlot *m_accPlot;
    QCustomPlot *m_gyrPlot;
    QCustomPlot *m_magPlot;
    QCustomPlot *m_anglePlot;

    QTimer *m_timer;
    double m_tickCounter;

    QVector<double> m_acc_x_Values;
    QVector<double> m_acc_y_Values;
    QVector<double> m_acc_z_Values;

    QVector<double> m_gyr_x_Values;
    QVector<double> m_gyr_y_Values;
    QVector<double> m_gyr_z_Values;

    QVector<double> m_mag_x_Values;
    QVector<double> m_mag_y_Values;
    QVector<double> m_mag_z_Values;

    QVector<double> m_angle_x_Values;
    QVector<double> m_angle_y_Values;
    QVector<double> m_angle_z_Values;


    QVector<double> m_timestamps;



private slots:
    void timerCounter();

signals:

public slots:
    void plotting(const bool &enable);

};

#endif // DATAPLOT_H
