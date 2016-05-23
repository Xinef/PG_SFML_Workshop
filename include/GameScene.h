#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <list>
#include "Scene.h"
#include "Player.h"
#include "Plasma.h"
#include "Enemy.h"
#include "EnemyPlasma.h"
#include "Explosion.h"

typedef std::list<Plasma> PlasmaSeq;
typedef std::list<Enemy> EnemySeq;
typedef std::list<EnemyPlasma> EnPlasmaSeq;
typedef std::list<Explosion> ExplosionSeq;

class GameScene : public Scene
{
    public:
        static float difficulty;

        GameScene();
        void draw(sf::RenderWindow &app);
        void runLogic(float deltaTime, Game &game);
        void handleEvent(sf::Event event, Game &game);
        void restart(Game& game);
    protected:
    private:
        void shooting(float deltaTime, Game& game);
        void spawningEnemies(float deltaTime, Game& game);
        void flyEnemyPlasma(float deltaTime, Game& game);

        float bgMotion = 0.0f;
        float bgSpeed = 200.0f;

        Player player;
        float cooldown = 0.0f;
        float rateOfFire = 0.2f;
        int score = 0;
        sf::Text scoreText;
        sf::Text escText;

        Player player2;
        float cooldown2 = 0.0f;
        float rateOfFire2 = 0.2f;
        int score2 = 0;
        sf::Text scoreText2;

        PlasmaSeq plasma;
        EnemySeq enemies;
        EnPlasmaSeq enPlasma;
        ExplosionSeq explosions;

        float enemySpawnCooldown = 0.0f;
        float enemyRateOfSpawn = 0.5f;
        int enemyScoreValue = 1;
        float enemyCooldown = 0.0f;
        float enemyRateOfFire = 2.0f;
};

#endif // GAMESCENE_H
