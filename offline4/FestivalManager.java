/* This class stores information of a festival which are name, starting date and list of events that will take place during the festival. */
public class FestivalManager {
    private String name;
    private String startDate;
    private Event[] events;
    int eventsAdded = 0;

    // Task: Write code for the constructor below to initialize the member variables
    // properly
    public FestivalManager(String name, String startDate, int maxEventCount) {
        // write your code here
        this.name = name;
        this.startDate = startDate;
        this.events = new Event[maxEventCount];
    }

    // Task: Write code for the function below. This function adds an event to this
    // festival. Check for the following case: (i) total event count does not exceed
    // the maximum number of events allowed for this festival
    public void addEvent(Event e) {
        // write your code here
        if (eventsAdded >= events.length)
            return;
        /*
         * events[eventsAdded].setEventDate(e.getEventDate());
         * events[eventsAdded].setEventName(e.getEventName());
         * events[eventsAdded].setEventLocation(e.getEventLocation());
         * eventsAdded++;
         */
        // write your code here
        events[eventsAdded] = new Event(e.getEventName(), e.getEventDate(), e.getEventLocation(),
                e.getMaxparticipants()); // Assuming maximumParticipants is available in the scope
        eventsAdded++;
    }

    // Task: Write code for the function below. This function registers a student
    // for an event in this festival. Check for the following case: (i) event does
    // not exist
    public void registerStudent(String eventName, Student s) {
        // Write your code here
        int index = -1;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventName().equals(eventName))
                index = i;
        }
        if (index == -1)
            return;
        else {
            events[index].addParticipant(s);
            return;
        }
    }

    // Task: Write code for the function below. The function shows the details of
    // this festival. Make sure the output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here
        System.out.println("Festival Name:" + name);
        System.out.println("Festival Starting Date:" + startDate);
        System.out.println("Festival Events:");
        for (int i = 0; i < eventsAdded; i++) {
            events[i].showDetails();
        }
    }

    // Task: Write code for the function below. This function shows details of the
    // event in the argument. Check for the following case: (i) event does not exist
    public void showEvent(String eventName) {
        // Write your code here
        int index = -1;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventName().equals(eventName))
                index = i;
        }
        if (index == -1)
            return;
        else {
            events[index].showDetails();
        }
    }

    // Task: Write code for the function below. This function shows details of the
    // events that will start on the date passed as its argument. Check for the
    // following case: (i) event does not exist
    public void showEventsOnDate(String eventDate) {
        // Write your code here
        int index = -1;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventDate().equals(eventDate)) {
                System.out.println(events[i].getEventName());
                index = i;
            }
        }
        if (index == -1)
            return;
    }

    // Task: Write code for the function below. This function shows the details of
    // the events with maximum number of participants. If there are multiple events,
    // show all.
    public void eventWithHighestParticipants() {
        // Write your code here
        int maxParticipants = -1;
        for (int i = 0; i < eventsAdded; i++) {
            if (maxParticipants < events[i].getParticipantsAddedSoFar())
                maxParticipants = events[i].getParticipantsAddedSoFar();
        }
        for (int i = 0; i < eventsAdded; i++) {
            if (maxParticipants == events[i].getParticipantsAddedSoFar())
                events[i].showDetails();
        }
    }

    // Task: Write code for the function below. This function takes a student Id as
    // input and then lists all the events this particular student has registered
    // for. Make sure your output matches the supplied sample output.
    public void showEventsForStudent(String studentId) {
        // Write your code here
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getStudent(studentId) != null) {
                if (events[i].getStudent(studentId).getId().equals(studentId))
                    System.out.println(events[i].getEventName());
            }
        }
    }

    // Task: Write code for the function below. This functions takes an event's name
    // and a student's ID as arguments and then removes the student from the
    // registered student list of the event. Check for the following cases: (i)
    // event does not exist, (ii) student is not registered for the event
    public void cancelRegistration(String eventName, String studentId) {
        // Write your code here
        int index = -1;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventName().equals(eventName)) {
                index = i;
                break;
            }
        }
        if (index == -1)
            return;
        events[index].removeParticipant(studentId);

    }
}
