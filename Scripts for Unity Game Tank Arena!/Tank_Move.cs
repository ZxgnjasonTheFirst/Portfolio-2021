using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tank_Move : MonoBehaviour
{
    private Rigidbody tank;
    private float Speed = 4;
    private float minDistApart = 4f;
    private float zeroDist = 0.1f;
    private float tankLength = 0.5f;
    private int m_teamNumber = 0;
    public int teamNumber 
    { 
        get{ return m_teamNumber; } 
        set{ m_teamNumber = value; } 
    }

    private GameObject ClosestFriendlyTank;
    private GameObject EnemyTank;

    void Start()
    {
        tank = this.GetComponent<Rigidbody>();
        EnemyTank = FindTargetTank();
    }

    // Update is called once per frame
    public void FixedUpdate()
    {
        MoveToEnemyTank();
    }

    public void Controls(string AIInput = "")
    {
        if (/*Input.GetKey(inputs[0]) ||*/ AIInput == "UP")
        {
            transform.rotation = Quaternion.Euler(0, 0, 0);
            transform.Translate(Vector3.forward * Time.deltaTime * Speed);
        }
        else if (/*Input.GetKey(inputs[1]) ||*/ AIInput == "LEFT")
        {
            transform.rotation = Quaternion.Euler(0, -90, 0);
            transform.Translate(Vector3.forward * Time.deltaTime * Speed);

        }
        else if (/*Input.GetKey(inputs[2]) ||*/ AIInput == "DOWN")
        {
            transform.rotation = Quaternion.Euler(0, 180, 0);
            transform.Translate(Vector3.forward * Time.deltaTime * Speed);
        }
        else if (/*Input.GetKey(inputs[3]) ||*/ AIInput == "RIGHT")
        {
            transform.rotation = Quaternion.Euler(0, 90, 0);
            transform.Translate(Vector3.forward * Time.deltaTime * Speed);
        }

    }

    // private GameObject FindClosestEnemyTank()
    // {
    //     GameObject[] otherTankInstances = GameObject.FindGameObjectsWithTag("Player");
    //     GameObject minG = null;
    //     float minDist = Mathf.Infinity;
    //     foreach(GameObject otherTank in otherTankInstances)
    //     {
    //         if (otherTank.GetComponent<Tank_Move>().teamNumber != teamNumber)
    //         {
    //             float dist = Vector3.Distance(transform.position, otherTank.transform.position);
    //             if (dist < minDist)
    //             {
    //                 minG = otherTank;
    //                 minDist = dist;
    //             }
    //         }
    //     }
    //     return minG;
    // }

    private GameObject FindClosestTank()
    {
        GameObject[] otherTankInstances = GameObject.FindGameObjectsWithTag("Player");
        GameObject minG = null;
        float minDist = Mathf.Infinity;
        foreach(GameObject otherTank in otherTankInstances)
        {   
            if(otherTank.GetComponent<Tank_Move>().teamNumber != this.teamNumber)
            {
                float dist = Vector3.Distance(transform.position, otherTank.transform.position);
                if (dist < minDist)
                {
                    minG = otherTank;
                    minDist = dist;
                }
            }
        }
        return minG;
    }
    

    public void MoveToEnemyTank()
    {
        if (EnemyTank)
        {   
            Debug.Log("MovingTowards");         
            MoveTowards(EnemyTank);
        }
        else
        {
            EnemyTank = FindTargetTank();
        }
        // else if (ClosestFriendlyTank)
        // {
        //     Debug.Log("MovingAway");
        //     MoveAway(ClosestFriendlyTank);
        // }    
        
    }

    public void MoveTowards(GameObject ClosestEnemyTank)
    {
        float DistanceX = 0.0f;
        float DistanceZ = 0.0f;
        DistanceX = transform.position.x - ClosestEnemyTank.transform.position.x;
        DistanceZ = transform.position.z - ClosestEnemyTank.transform.position.z;

        if (ClosestEnemyTank)
            if (Mathf.Abs(DistanceX) < Mathf.Abs(DistanceZ))
            {
                if (DistanceX > zeroDist)
                {
                    Controls("LEFT");
                }
                else if (DistanceX < -zeroDist)
                {
                    Controls("RIGHT");
                }
            }
            else if (Mathf.Abs(DistanceZ) < Mathf.Abs(DistanceX))
            {
                if (DistanceZ > zeroDist)
                {
                    Controls("DOWN");
                }
                else if (DistanceZ < -zeroDist)
                {
                    Controls("UP");
                }
            }

            if (Mathf.Abs(DistanceX) < zeroDist)
            {
                if (DistanceZ > tankLength)
                {
                    Controls("DOWN");

                    if(Mathf.Abs(DistanceZ) < minDistApart)
                    {
                        this.GetComponent<Tank_Fire>().Fire("FIRE");
                    }
                }
                else if (DistanceZ < -tankLength)
                {
                    Controls("UP");

                    if(Mathf.Abs(DistanceZ) < minDistApart)
                    {
                        this.GetComponent<Tank_Fire>().Fire("FIRE");
                    }
                }
            }
            else if (Mathf.Abs(DistanceZ) < zeroDist)
            { 
                if(DistanceX > tankLength)
                {
                    Controls("LEFT");

                    if(Mathf.Abs(DistanceX) < minDistApart)
                    {
                    this.GetComponent<Tank_Fire>().Fire("FIRE");
                    }
                }
                else if (DistanceX < -tankLength)
                {
                    Controls("RIGHT");

                    if(Mathf.Abs(DistanceX) < minDistApart)
                    {
                        this.GetComponent<Tank_Fire>().Fire("FIRE");
                    }
                }
            }
    }

    private GameObject FindTargetTank()
    {
        int increment = 0;
        int safeGuard = 40;
        GameObject[] otherTankInstances = GameObject.FindGameObjectsWithTag("Player");
        int randIndex = Random.Range(0, otherTankInstances.Length);

        GameObject TargettedTank = otherTankInstances[randIndex];

        while (TargettedTank.GetComponent<Tank_Move>().teamNumber == this.teamNumber)
        {
            randIndex = Random.Range(0, otherTankInstances.Length);
            TargettedTank = otherTankInstances[randIndex];
            if (increment >= safeGuard)
            {
                return null;
            }
            increment++;
        }

        return TargettedTank;
    }

}
