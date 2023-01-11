import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:digitalkey/digitalkey.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {

  String _platformVersion = 'Unknown';
  String zuid = 'sdcsacsangd';
  String fetchKeyTxt = '';
  String init = '';
  final _digitalkeyPlugin = Digitalkey();

  @override
  void initState() {
    super.initState();
    initPlatformState();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initPlatformState() async {
    String platformVersion;
    // Platform messages may fail, so we use a try/catch PlatformException.
    // We also handle the message potentially returning null.
    try {
      platformVersion =
          await _digitalkeyPlugin.initZDK(server: "",brand: "") ?? 'Unknown platform version';
    } on PlatformException {
      platformVersion = 'Failed to get platform version.';
    }

    // If the widget was removed from the tree while the asynchronous platform
    // message was in flight, we want to discard the reply rather than calling
    // setState to update our non-existent appearance.
    if (!mounted) return;

    setState(() {
      _platformVersion = platformVersion;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Center(
              child: Text(init),
            ),
            Center(
              child: Text(fetchKeyTxt.toString()),
            ),
            Center(
              child: Text('Running on: $_platformVersion\n'),
            ),
            MaterialButton(onPressed: () {
              setState(() {
                setUpZDK();
              });

            },child: const Text("initZDK"),),
            MaterialButton(onPressed: () {
              setState(() {
                fetchKey();
              });

            },child: const Text("fetchKey"),),
            MaterialButton(onPressed: (){
              setState(() {
                unLockDoor();
              });
            },child: const Text("unLockDoor"),),
          ],
        ),
      ),
    );
  }

  fetchKey() async{
    fetchKeyTxt =  await _digitalkeyPlugin.fetchKey();

  }

  setUpZDK() async{
    init =  (await _digitalkeyPlugin.initZDK(brand: "",server: ""))!;
  }

  unLockDoor() async{
    await _digitalkeyPlugin.unLockDoor(keyZid: zuid);
  }
}
