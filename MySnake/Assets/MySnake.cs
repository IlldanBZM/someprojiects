using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class MySnake : MonoBehaviour
{
    [SerializeField]
    private int Height;
    [SerializeField]
    private int Weight;
    private int sn_x, sn_y;
    private List<Vector2> SnakePos;
    private List<GameObject> SnakeObject;
    private GameObject FoodObject;
    private Vector2 FoodPos;
    private char NowKey;
    private char NextKey;
    private bool IsOver = false;
    public GameObject Food;
    public GameObject Snake;
    private float Timer = 0;

    void Start()
    {
        SnakePos = new List<Vector2>(3);
        SnakeObject = new List<GameObject>(3);
        sn_x = Weight / 4;
        sn_y = Height / 4;
        SnakePos.Add(new Vector2(sn_x, sn_y));
        SnakePos.Add(new Vector2(sn_x - 1, sn_y));
        SnakePos.Add(new Vector2(sn_x - 2, sn_y));
        for (int i = 0; i < SnakePos.Count; i++)
        {
            SnakeObject.Add(Instantiate(Snake));
            SnakeObject[i].transform.position = SnakePos[i];
        }
        FoodPos = new Vector2(Height / 2, Weight / 2);
        FoodObject = Instantiate(Food);
        FoodObject.transform.position = FoodPos;
        NowKey = 'd';
        NextKey = 'd';
    }

    void Update()
    {
        Timer += Time.deltaTime;
        if (Input.GetKey(KeyCode.W)) NextKey = 'w';
        if (Input.GetKey(KeyCode.A)) NextKey = 'a';
        if (Input.GetKey(KeyCode.S)) NextKey = 's';
        if (Input.GetKey(KeyCode.D)) NextKey = 'd';
        if ((NowKey == 'd' && NextKey != 'a') |
           (NowKey == 'w' && NextKey != 's') |
           (NowKey == 'a' && NextKey != 'd') |
           (NowKey == 's' && NextKey != 'w'))
            NowKey = NextKey;
        if (Timer > 0.2)
        {
            Timer = 0;
            //判断是否死亡
            int count = 0;
            foreach (Vector2 a in SnakePos)
            {
                if (a == SnakePos[0]) count++;
                if (count == 2) IsOver = true;
            }
            if (SnakePos[0].x == 0 || SnakePos[0].x == Weight ||
                SnakePos[0].y == 0 || SnakePos[0].y == Height)
                IsOver = true;
            if (IsOver)
            {
                UnityEngine.SceneManagement.SceneManager.LoadScene("GameEnd");
            }
            //蛇向前走
            Vector2 NewHeadPos = SnakePos[0];
            if (NowKey == 'w') NewHeadPos.y++;
            if (NowKey == 's') NewHeadPos.y--;
            if (NowKey == 'a') NewHeadPos.x--;
            if (NowKey == 'd') NewHeadPos.x++;
            SnakePos.Insert(0, NewHeadPos);
            SnakeObject.Insert(0, Instantiate(Snake));
            SnakeObject[0].transform.position = SnakePos[0];
            //判断蛇是否吃到食物
            if (SnakePos[0] == FoodPos)
            {
                bool flag = true;
                while (true)
                {
                    Vector2 NewFoodPos = new Vector2(Random.Range(1, Weight - 1), Random.Range(1, Height - 1));
                    Debug.Log(Weight);
                    Debug.Log(NewFoodPos);
                    foreach (Vector2 a in SnakePos)
                    {
                        if (a == NewFoodPos) flag = false;
                    }
                    if (flag == false) continue;
                    else
                    {
                        FoodPos = NewFoodPos;
                        break;
                    }
                }
                Destroy(FoodObject);
                FoodObject= Instantiate(Food);
                FoodObject.transform.position = FoodPos;
            }
            else
            {
                SnakePos.RemoveAt(SnakePos.Count - 1);
                GameObject one = SnakeObject[SnakeObject.Count - 1];
                SnakeObject.RemoveAt(SnakeObject.Count - 1);
                Destroy(one);
            }
        }
    }
}