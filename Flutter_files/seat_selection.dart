import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:project/pages/ticket.dart';
import 'package:firebase_auth/firebase_auth.dart';
void writeUserIdToDatabase(int selectedSlot) {
 final databaseReference = FirebaseDatabase.instance.ref();
 final selectedSlotReference = databaseReference.child('/Parking
Slots/$selectedSlot/');
 final User? user = FirebaseAuth.instance.currentUser;
 final String? email = user?.email;
 selectedSlotReference.child('UserID').set(email);
 selectedSlotReference.child('Vacancy').set('clear');
}
class SlotBookingPage extends StatefulWidget {
 const SlotBookingPage({Key? key}) : super(key: key);
 @override
 _SlotBookingPageState createState() => _SlotBookingPageState();
}
class _SlotBookingPageState extends State<SlotBookingPage> {
 int _selectedSlot = -1;
 @override
 Widget build(BuildContext context) {
 return Scaffold(
 appBar: AppBar(
 title: Text('Slot Booking'),
 ),
 body: Column(
 mainAxisAlignment: MainAxisAlignment.center,
 crossAxisAlignment: CrossAxisAlignment.center,

 children: [
 Text(
 'Select your slot:',
 style: TextStyle(fontSize: 18),
 ),
 SizedBox(height: 20),
 Expanded(
 child: CustomScrollView(
 slivers: [
 SliverGrid(
 gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
 crossAxisCount: 2,
 childAspectRatio: 2 / 3,
 ),
 delegate: SliverChildBuilderDelegate(
 (BuildContext context, int index) {
 return GestureDetector(
 onTap: () {
 setState(() {
 _selectedSlot = index;
 });
 },
 child: Container(
 margin: EdgeInsets.all(5),
 decoration: BoxDecoration(
 color: _selectedSlot == index
 ? Colors.green
 : Colors.grey,
 borderRadius: BorderRadius.circular(10),
 ),
 child: Center(
 child: Text(
 '${index + 1}',
 style: TextStyle(

 color: Colors.white,
 fontSize: 20,
 fontWeight: FontWeight.bold,
 ),
 ),
 ),
 ),
 );
 },
 childCount: 5,
 ),
 ),
 ],
 scrollDirection: Axis.horizontal,
 physics: BouncingScrollPhysics(),
 ),
 ),
 SizedBox(height: 20),
 ElevatedButton(
 onPressed: () {
 if (_selectedSlot == -1) {
 // show an error message or disable the button
 return;
 }
 int selectedSlot = _selectedSlot + 1;
 writeUserIdToDatabase(selectedSlot);
 print('Selected parking slot: $selectedSlot');
 Navigator.push(
 context,
 MaterialPageRoute(builder: (context) =>
TicketConfirmationPage(selectedSlot: selectedSlot)),
 );
 },
 child: Text('Book Slot'),

 ),
 ],
 ),
 );
 }
}