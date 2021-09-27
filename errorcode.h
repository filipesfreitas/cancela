struct LowRssi : public exception {
   const char * what () const throw () {
      return "Low RSSI";
   }
};

struct TcpConnection : public exception {
   const char * what () const throw () {
      return "Low RSSI";
   }
};
struct GprsConnection : public exception {
   const char * what () const throw () {
      return "Low RSSI";
   }
};