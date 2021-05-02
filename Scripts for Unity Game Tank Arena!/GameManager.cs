using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager GM;

    private Color[] TeamColors = {Color.blue, Color.red, Color.white, Color.black};

    public GameObject tankPrefab;
    
    [HideInInspector]
    public Team_Manager[] TeamManagers;
    // Start is called before the first frame update

    void Start()
    {
        GM = this;
        
        setup();
        
        for (int i = 0; i < TeamManagers.Length; i++)
        {
            if (TeamManagers[i])
            {
                TeamManagers[i].teamNumber = i;
                TeamManagers[i].playerColor = TeamColors[i];
                TeamManagers[i].tankPrefab = tankPrefab;
                TeamManagers[i].setup();
                Debug.Log("TeamManager[" + i + "]'s teamNumber is: " + TeamManagers[i].teamNumber);
            }
        }
    }
    
    private void setup()
    {
        GameObject[] TeamManagersObjs = GameObject.FindGameObjectsWithTag("TeamManager");
        TeamManagers = new Team_Manager[TeamManagersObjs.Length];
        for (int i = 0 ; i < TeamManagersObjs.Length; i++)
        {
            int realTeamNumber = i + 1;
            TeamManagers[i] = GameObject.Find("TeamManager " + realTeamNumber).GetComponent<Team_Manager>();
        }

    }

    public void restart()
    {
        foreach(Team_Manager TeamManager in TeamManagers)
        {
            TeamManager.resetAllTanks();
            TeamManager.spawnTeam();
        }
    }


    public void exitGame()
    {
        Application.Quit();
    }
}
