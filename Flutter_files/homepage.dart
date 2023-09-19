import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:project/pages/login_page.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:project/firebase_options.dart';
import 'package:project/pages/seat_selection.dart';
class HomePage extends StatelessWidget {
 const HomePage({Key? key}) : super(key: key);
void signOutUser() async{
 await FirebaseAuth.instance.signOut();
}
 @override
 Widget build(BuildContext context) {
 return Scaffold(
 appBar: AppBar(
 foregroundColor: Colors.black,
 leading: BackButton(
 onPressed: ()=> this.signOutUser(),
 ),
 title: Text(' Select a Parking Slot'),
 ),
 body: Center(
 child: Column(
 mainAxisAlignment: MainAxisAlignment.center,
 crossAxisAlignment: CrossAxisAlignment.center,
 children: [
 Text('Logged In:',
 style: TextStyle(fontSize: 18),
 ),
 SizedBox(height: 20),
 ElevatedButton(
 onPressed: () {
 Navigator.push(
 context,
 MaterialPageRoute(builder: (context) =>SlotBookingPage()),
 );
 },
 child: Text('Select a Slot'),
 )
 ],
 ),
 ),
 );
 }
}