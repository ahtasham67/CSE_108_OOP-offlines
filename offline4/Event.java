/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */
public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    int participantsAdded = 0; // variable to keep track of number of participants so far added

    // Task: Write code for the constructor below to initialize the member variables
    // properly
    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        // write your code here
        this.eventName = eventName;
        this.eventDate = eventDate;
        this.eventLocation = eventLocation;
        this.registeredStudents = new Student[maximumParticipants];
    }

    // Task: Write getters and setters for Event attributes as required
    public void setEventName(String eventName) {
        this.eventName = eventName;
    }

    public void setEventDate(String eventDate) {
        this.eventDate = eventDate;
    }

    public void setEventLocation(String eventLocation) {
        this.eventLocation = eventLocation;
    }

    public String getEventName() {
        return eventName;
    }

    public String getEventDate() {
        return eventDate;
    }

    public String getEventLocation() {
        return eventLocation;
    }

    // adding this additional method for public void showEventsForStudent(String
    // studentId) method
    public Student getStudent(String studentId) {
        // int index = -1;
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getId().equals(studentId))
                return registeredStudents[i];
            // index = i;
        }
        return null;
        /*
         * if(index!=-1)
         * return registeredStudents[index];
         * else return null;
         */
    }

    public int getMaxparticipants() {
        return registeredStudents.length;
       //return participantsAdded;
    }

    public int getParticipantsAddedSoFar(){
        return participantsAdded;
    }

    // Task: Write your code for the function below. This functions adds a
    // participant to this event. Check for the following cases: (i) total
    // participant count does not exceed the maximum participant count, (ii) the
    // studentId is not already added.
    public void addParticipant(Student student) {
        // write your code here
        if (participantsAdded >= registeredStudents.length) {
            // System.out.println("Overflow");
            return;
        }
        boolean isAlreadyAdded = false;
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getId().equals(student.getId())) {
                isAlreadyAdded = true;
                System.out.println("Student already in the event");
                break;
            }
        }
        if (isAlreadyAdded)
            return;
        else {
            /*
             * registeredStudents[participantsAdded].setName(student.getName());
             * registeredStudents[participantsAdded].setId(student.getId());
             */
            registeredStudents[participantsAdded] = new Student(student.getName(), student.getId());
            participantsAdded++;
        }

    }

    // Task: Write code for the function below. This function shows the details of
    // an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here
        System.out.println("Name:" + eventName);
        System.out.println("Date:" + eventDate);
        System.out.println("Location:" + eventLocation);
        System.out.println("Registered Participants:");
        for (int i = 0; i < participantsAdded; i++) {
            // System.out.println("Name:" + registeredStudents[i].getName() + "," + "Id:" +
            // registeredStudents[i].getId());
            // System.out.println("Id:" + registeredStudents[i].getId());
            registeredStudents[i].showDetails();
        }
    }

    // Task: Write code for the function below. This function check whether the
    // studentId in the argument has registered for this event or not. Return true
    // if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        // Write your code here
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getId().equals(studentId))
                return true;
        }
        return false;
    }

    // Task: Write code for the function below. This function removes a participant
    // from this event. Check for the following cases: (i) the student Id is not
    // regiseterd.
    public void removeParticipant(String studentId) {
        // Write your code here
        if (isRegistered(studentId)==false)
            return;
        int index = -1;
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getId().equals(studentId)) {
                index = i;
                break;
            }
        }
        // shifting
        if (index == participantsAdded - 1) {
            participantsAdded--;
            return;
        } else {
            for (int i = index; i < participantsAdded - 1; i++) {
                registeredStudents[i] = registeredStudents[i + 1];
            }
            participantsAdded--;
            return;
        }
    }

}