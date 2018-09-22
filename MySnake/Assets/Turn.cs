using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Turn : MonoBehaviour {
	void Start () {
		
	}
	void Update () {
        if (Input.GetKey("r"))
            UnityEngine.SceneManagement.SceneManager.LoadScene("MyScene");
        
        if (Input.GetKey("e"))  Application.Quit(); 
	}
}
