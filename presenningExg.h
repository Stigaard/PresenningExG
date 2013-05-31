/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2013  Morten Stigaard Laursen <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef PRESENNINGEXG_H
#define PRESENNINGEXG_H

#include <qt4/QtCore/QThread>
#include <qt4/QtCore/QSemaphore>
#include <qt4/QtCore/QQueue>
#include <opencv2/opencv.hpp>

class presenningExg : public QThread
{
  Q_OBJECT
public:
    presenningExg(void);
    ~presenningExg();
    void run();
  static void BayerGR16ToExG(cv::InputArray in, cv::OutputArray out);
  static void downsample(cv::InputArray in, cv::OutputArray out);
public slots:
  void newBayerGRImage(cv::Mat img, qint64 timestampus);
signals:
  void newImage(cv::Mat img, qint64 timestampus);
private:
  QSemaphore semImg;
  QQueue<cv::Mat> Imgs;
  QQueue<qint64> timestamps;
  bool updateptimer;
  bool abort;
};

#endif // PRESENNINGEXG_H
