import java.util.Scanner;

/* This is the driver class for this project. You need to run this class with three command line arguments corresponding to the name, starting date and maxinum number of allowed events of a festival. For exmaple run the below command from the termincal:
java FestivalApp "CSE Fest 2023" "2023-07-15" 10*/
public class FestivalApp {

    public static void main(String[] args) {
        // Task: The program will be run with three command line arguements related to a
        // festival- (i) the festival's name, (ii) its starting date and (iii) the
        // maximum number of events allowed in the festival. Create a FestivalManager
        // object named 'festivalManager' and initialize it with the values passed from
        // the command line as: FestivalManager festivalManager = new
        // FestivalManager(...); Generate error if the required parameters are not
        // passed from the command line.
        if (args.length < 3) {
            System.out.println("Error");
            System.exit(0);
        }
        FestivalManager festivalManager = new FestivalManager(args[0], args[1], Integer.parseInt(args[2]));
        // Write your code here
        // FestivalManager festivalManager = new FestivalManager("CSE Fest 2023" ,
        // "2023-07-20", 10);

        int choice;
        Scanner scanner = new Scanner(System.in);

        do {
            // the following lines of code show a menu to take user's choice
            System.out.println("Menu:");
            System.out.println("1. Add an event");
            System.out.println("2. Register student in an event");
            System.out.println("3. View festival details");
            System.out.println("4. View specific event");
            System.out.println("5. View Event on Date");
            System.out.println("6. View event with maximum participants");
            System.out.println("7. View events for students");
            System.out.println("8. Cancel registration");
            System.out.println("9. Exit");
            System.out.print("Enter option: ");

            choice = scanner.nextInt();

            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1: // Add an event
                    /*
                     * Task: using the scanner object, read the following information for an event:
                     * (i) name as a string, (ii) starting date as a string in 'YYYY-MM-DD' format,
                     * (iii) location as astring, and (iv) max number of participants allowed in the
                     * event as an integer. Invoke the function 'add event' of 'Festival Manager' to
                     * add the event, i.e., call festivalManager.addEvent(...)
                     */

                    /*
                     * Enter option: 1
                     * Enter event name: Hackathon
                     * Enter event date (YYYY-MM-DD): 2023-07-23 Enter event location: ECE Building
                     * Enter maximum participants: 30
                     * Event added successfully!
                     */
                    // Write your code here
                    System.out.println("Enter event name: ");
                    String name = scanner.nextLine();
                    System.out.println("Enter event date (YYYY-MM-DD):");
                    String date = scanner.nextLine();
                    System.out.println("Enter event location:");
                    String location = scanner.nextLine();
                    System.out.println("Enter maximum participants:");
                    int participantsNum = scanner.nextInt();
                    Event event = new Event(name, date, location, participantsNum);
                    festivalManager.addEvent(event);
                    System.out.println("Event added successfully!");
                    break;

                case 2:// Register a student in an event
                    /*
                     * Task: read the name and id of a student and an event name. Then register the
                     * student in the event by calling the function:
                     * festivalManager.registerStudent(...)
                     * 
                     * Enter option: 2
                     * Enter student name: Mr. B
                     * Enter student ID: 2021050061
                     * Enter event name:
                     * Hackathon
                     * Student registration completed.
                     * 
                     */

                    // Write your code here
                    System.out.println("Enter student name: ");
                    String StuName = scanner.nextLine();
                    System.out.println("Enter student ID: ");
                    String StuID = scanner.nextLine();
                    System.out.println("Enter event name:");
                    String eventName = scanner.nextLine();

                    Student st = new Student(StuName, StuID);
                    festivalManager.registerStudent(eventName, st);
                    System.out.println("Student registration completed.");
                    break;

                case 3: // View festival details

                    festivalManager.showDetails();

                    break;

                case 4: // View event details
                    /*
                     * Task: read the name of an event and then show the details for the event by
                     * calling the function: festivalManager.showEvent(...);
                     * 
                     * Enter option: 4
                     * Enter event name: Game Jam
                     * Name: Game Jam
                     * Date: 2023-07-22
                     * Location: ECE Building
                     * Registered Participants:
                     * Name: Mr. H, Id: 2021050100 Name: Mr. A, Id: 202105001
                     */

                    // Write your code here
                    System.out.println("Enter event name:");
                    String eventname = scanner.nextLine();
                    festivalManager.showEvent(eventname);
                    break;

                case 5:/*
                        * Enter event date: 2023-07-23
                        * Events on 2023-07-23 are: Hackathon
                        */

                    System.out.println("Enter event date:");
                    String eventDate = scanner.nextLine();
                    System.out.println("Events on "+eventDate+" are:");
                    festivalManager.showEventsOnDate(eventDate);
                    break;

                case 6: // View event with maximum participants
                    System.out.println("Event with highest participants:");
                    festivalManager.eventWithHighestParticipants();
                    break;

                case 7: // View events for students
                    /*
                     * Task: read the id of a student and then show the events the student is
                     * participating in by calling the function:
                     * festivalManager.showEventsForStudent(...);
                     */

                    // Write your code here
                    System.out.println("Enter student id:");
                    String stNum = scanner.nextLine();
                    System.out.println("Student " + stNum + " is registered in :");
                    festivalManager.showEventsForStudent(stNum);
                    break;

                case 8: // Cancel registration
                    /*
                     * Task: read the id of a student and an event name. Then remove the student
                     * from the participant list of the event by calling the function:
                     * festivalManager.cancelRegistration(...);
                     */

                    // Write your code here
                    System.out.println("Enter student id:");
                    String stuNum = scanner.nextLine();
                    System.out.println("Enter event name:");
                    String eve = scanner.nextLine();
                    festivalManager.cancelRegistration(eve, stuNum);
                    System.out.println("Successfully removed id " + stuNum + " from event " + eve);
                    break;

                case 9:
                    System.out.println("Exiting the program.");
                    break;

                default:
                    System.out.println("Invalid option. Please try again.");
            }

            System.out.println();
        } while (choice != 9);

        scanner.close();
    }
}
