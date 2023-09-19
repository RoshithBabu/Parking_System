import 'package:flutter/material.dart';
class TicketConfirmationPage extends StatelessWidget {
 final int selectedSlot;
 const TicketConfirmationPage({Key? key, required this.selectedSlot})
 : super(key: key);
 @override
 Widget build(BuildContext context) {
 return Scaffold(
 appBar: AppBar(
 title: Text('Ticket Confirmation'),
 ),
 body: Center(
 child: Column(
 mainAxisAlignment: MainAxisAlignment.center,
 crossAxisAlignment: CrossAxisAlignment.center,
 children: [
 Text(
 'Your parking slot has been booked!',
 style: TextStyle(
 fontSize: 20,
 fontWeight: FontWeight.bold,
 ),
 ),
 SizedBox(height: 20),
 Text(
 'Selected Slot:',
 style: TextStyle(fontSize: 18),
 ),
 SizedBox(height: 10),

 Column(
 children: [
 Text(
 'Slot $selectedSlot: ',
 style: TextStyle(
 fontSize: 24,
 fontWeight: FontWeight.bold,
 ),
 ),
 ],
 ),
 SizedBox(height: 30),
 ElevatedButton(
 onPressed: () {
 Navigator.popUntil(context, ModalRoute.withName('/'));
 },
 child: Text('Pay Now for 1 hour'),
 ),
 ],
 ),
 ),
 );
 }
}