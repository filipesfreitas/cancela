#include "errorcode.h"
class connection
{
  private:
    struct status
    {
      bool connection;
    };
  public:
    connection();
    ~connection();
    getStatus() {
      return this->status;
    }
    setStatus() {

    }
};

class  Wireless : connection
{
  private:
    struct status
    {
      float RSSI;
      bool connection;
    };
  public:
    Wireless();
    ~Wireless();
    getStatus() {
      return this->status;
    }
};

class WiFi: Wireless
{
  private:
    struct status
    {
      float RSSI;
      bool connection;
      string ssid;
      string pass;
    };

  public:
    WiFi();
    ~WiFi();
    status getStatus() {
      return this->status;
    }
    status setStatus(float RSSI, string ssid, string pass) {
      this -> RSSI = RSSI;
      this -> ssid = ssid;
      this -> pass = pass;
    }
};

class GPRS: Wireless
{
  private:
    struct status
    {
      float RSSI;
      bool connection;
      string apn;
      string gprsUser;
      string gprsPass;
      string server;
      int port;
    };

  public:
    WiFi() {
      this -> status.RSSI = 0;
      this -> status.apn = "";
      this -> status.gprsPass = "";
      this -> status.gprsUser = "";
      this -> status.server = "";
      this -> status.port = 80;
      this -> status.connection = false;
    }
    ~WiFi();
    bool connection() {
      return this->status.connection;
    }
    float getRSSI(Serial atmodem) {
      this -> RSSI = atmodem -> print();
    }
    string getApn() {
      return this-> status.apn;
    }
    string getGprsPass() {
      return this->status.gprspass;
    }

    string getGprsUser() {
      return this->status.gprsuser;
    }

    string getServer() {
      return this->status.server;
    }
    int getPort() {
      return this->status.port;
    }
    status set(string apn, string  gprsPass, string gprsUser, string server , string port, Serial atmodem) {
      this -> status.RSSI = this -> getRSSI();
      this -> status.apn = apn;
      this -> status.gprsPass = gprsPass;
      this -> status.gprsUser = gprsUser;
      this -> status.server = server;
      this -> status.port = port;

    }
    bool reconnection(Serial *atmodem) {
      /* check gprs connection and try to restart*/
      try {
        /* check rssi for connection*/
        if ()
        {
          throw TcpConnection();
        }
        else if () {
          throw GprsConnection();
        }

      }
      catch (LowRssi& e) {
        /* Try send RSSI message*/

      }
      catch (GprsConnection& e) {
        /* Try gprsreconnetion network through restart SIM800*/

      }
      catch (TcpConnection& e) {
        /* Retry tcp connection to server*/
      }
    }
};


/*
   Conneciton handler calsses
    The conneciton handler classes works to test connection and

*/
