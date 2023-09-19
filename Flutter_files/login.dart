import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:project/components/button.dart';
import 'package:project/components/textfield.dart';
class LoginPage extends StatelessWidget {
 LoginPage({super.key});
// text editing controllers
 final usernameController = TextEditingController();
 final passwordController = TextEditingController();
//sign user-in method
 void signUserIn() async {
 await FirebaseAuth.instance.signInWithEmailAndPassword(
 email: usernameController.text,
 password: passwordController.text,
 );
}
 @override
 Widget build(BuildContext context) {
 return Scaffold(
 backgroundColor: Colors.grey[300],
 body: SafeArea(
 child: Center(
 child: Column(
 mainAxisAlignment: MainAxisAlignment.center,
 children: [
 const SizedBox(height:50),
 const Icon(
 Icons.car_rental,
 size: 100,

 ),
 const SizedBox(height: 50),
 Text(
 'Sign in to Smart Parking System',
 style: TextStyle(
 color: Colors.grey[700],
 fontSize: 16,
 ),
 ),
 const SizedBox(height:25),
 // username
 MyTextField(
 controller: usernameController,
 hintText:'Email Id',
 obscureText: false,
 ),
 const SizedBox(height:5),
 //password
 MyTextField(
 controller: passwordController,
 hintText:'Password',
 obscureText: true,
 ),
 const SizedBox(height: 10),
 Padding(padding: const EdgeInsets.symmetric(horizontal: 25.0),
 child: Row(
 mainAxisAlignment: MainAxisAlignment.end,
 children: [
 Text(
 'Forgot Password?',

 style: TextStyle(color: Colors.grey[600]),
 ),
 ],
 ),
 ),
 const SizedBox(height: 25),
 //signin button
 MyButton(
 onTap: signUserIn,
 ),
 const SizedBox(height: 25),
 Row(
 mainAxisAlignment: MainAxisAlignment.center,
 children: [
 Text('Not a member?'),
 const SizedBox(width: 4),
 const Text('Register Now',
 style: TextStyle(
 color: Colors.blue, fontWeight: FontWeight.bold
 ),
 ),
 ],
 ),
 ],
 ),
 ),
 )
 );
 }
}