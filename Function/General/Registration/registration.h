const string accountFile = "DataSet/accountUser.txt";
const string taskStudent = "Function/General/Registration/taskOfStudent.txt";
const string taskStaff = "Function/General/Registration/taskOfStaff.txt";

void login(std::string &idUser, bool &logingIn); //login to Moodle
void task(std::string idUser, bool &logingIn); //to show all the task that user can do
void logOut(std::string idUser, bool &logingIn); //to log out
void changePass(std::string idUser); //to change password