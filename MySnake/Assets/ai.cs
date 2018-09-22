//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;
//using UnityEngine.AI;

//public class ai : MonoBehaviour {
//    public Transform center_point;
//    private Vector3 force_dir;
//    public float radius;
//    public float m_speed;
//    // Use this for initialization
//    void Start()
//    {
//    }

//    // Update is called once per frame
//    void Update()
//    {
//        float distance = Vector3.Distance(center_point.position, gameObject.transform.position);
//        //Debug.Log(distance);
//        if (distance > radius)
//        {
//            force_dir = center_point.position - gameObject.transform.position;
//            GetComponent<Rigidbody>().AddForce(force_dir*30);
//        }
//        MoveControlByTranslateGetAxis();
//    }
//    void MoveControlByTranslateGetAxis()
//    {
//        float horizontal = Input.GetAxis("Horizontal"); //A D 左右
//        //float vertical = Input.GetAxis("Vertical"); //W S 上 下

//        transform.Translate(Vector3.forward * m_speed * Time.deltaTime);
//        transform.Translate(Vector3.right * horizontal * m_speed * Time.deltaTime);//A D 左右
//    }
//}

using UnityEngine;  
using System.Collections;  
  
public class ai : MonoBehaviour
{
    public GameObject target;
    public Camera cam;
    public GameObject centerObj;
    public GameObject roateObj;
    Quaternion qua;
    Vector3 lookdir;
    void Start()
    {
    }

    // Update is called once per frame  
    void Update()
    {
        cam.transform.LookAt(roateObj.transform);
        if (centerObj != null)
        {
            //roateObj围绕centerObj旋转，x,y不旋转  
            if (Input.GetKey(KeyCode.A))
            {
                roateObj.transform.RotateAround(centerObj.transform.position, new Vector3(0, 1, 1), 50f * Time.deltaTime);
                qua = roateObj.transform.rotation;
                qua.z = 0; qua.x = 0; qua.y = 0;
                roateObj.transform.rotation = qua;
            }
            else if(Input.GetKey(KeyCode.D))
            {
                roateObj.transform.RotateAround(centerObj.transform.position, new Vector3(1, 0, 1), 50f * Time.deltaTime);
                qua = roateObj.transform.rotation;
                qua.z = 0; 
                roateObj.transform.rotation = qua;
            }
            {
                roateObj.transform.RotateAround(centerObj.transform.position, target.transform.position, 50f * Time.deltaTime);
                //这里处理不然roateObj图片的显示位置发生变化  
                qua = roateObj.transform.rotation;
                qua.z = 0;
                roateObj.transform.rotation = qua;
            }
        }

    }




}


