interface Vehicle {
    String getType();
}

class Car implements Vehicle {
    @Override
    public String getType() {
        return "Car";
    }
}

class Bike implements Vehicle {
    @Override
    public String getType() {
        return "Bike";
    }
}

class Truck implements Vehicle {
    @Override
    public String getType() {
        return "Truck";
    }
}

abstract class VehicleFactory {
    abstract Vehicle createVehicle();
}

class CarFactory extends VehicleFactory {
    // Write your code here
    public Vehicle createVehicle() {
        Vehicle myCar = new Car();
        return myCar;
    }
}

class BikeFactory extends VehicleFactory {
    // Write your code here
    public Vehicle createVehicle() {
        Vehicle myBike = new Bike();
        return myBike;
    }
}

class TruckFactory extends VehicleFactory {
    // Write your code here
    public Vehicle createVehicle() {
        Vehicle myTruck = new Truck();
        return myTruck;
    }
}
