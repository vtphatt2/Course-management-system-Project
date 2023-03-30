const string accountFile = "DataSet/accountUser.txt";
const string taskStudent = "Function/General/Registration/taskOfStudent.txt";
const string taskStaff = "Function/General/Registration/taskOfStaff.txt";

void login(string &idUser, bool &logingIn); //login to Moodle
void task(string idUser, bool &logingIn); //to show all the task that user can do
void logOut(string idUser, bool &logingIn); //to log out
void changePass(string idUser); //to change password