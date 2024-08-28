#include "AIMoveBestRouteComponent.h"
#include "GameObjects.h"
#include "Map.h"
#include "FontManager.h"

AIMoveBestRouteComponent::AIMoveBestRouteComponent(GameObject* referenceObject, GameObject* targetObject)
    : AIMoveToComponent(referenceObject, targetObject), m_mapGraph(buildGraph())
{
#ifdef DEBUG_VERTEX
    m_text.setFont(FontManager::getInstance().getDefaultFont());

    m_text.setCharacterSize(48); // in pixels, not points!
    m_text.setFillColor(sf::Color::Blue);
    m_text.setOrigin(m_text.getGlobalBounds().getSize().x / 2, m_text.getGlobalBounds().getSize().y / 2);
#endif
}

void AIMoveBestRouteComponent::update(float dt)
{
    updatePath(m_mapGraph);
    const sf::Vector2u nextTileToMove = getNextTileToMove();
    const sf::Vector2f targetPosition = Map::GetInstance().getPositionFromTile(nextTileToMove);

    moveTo(dt, targetPosition);
}

void AIMoveBestRouteComponent::draw(sf::RenderWindow* window)
{
#ifdef DEBUG_VERTEX
    const Map::TilesMapType& mapTiles = Map::GetInstance().getAllTiles();

    for (unsigned y = 0; y < mapTiles.size(); y++)
    {
        for (unsigned x = 0; x < mapTiles[y].size(); x++)
        {
            const int vertixNumber = convertMapTileToVertix({ x, y });
            const sf::Vector2f position = Map::GetInstance().getPositionFromTile({ x, y });

            m_text.setPosition(position);
            m_text.setString(std::to_string(vertixNumber));

            window->draw(m_text);
        }
    }
#endif 

#ifdef DEBUG_PATH
    for (auto vertex : m_path)
    {
        sf::RectangleShape path = sf::RectangleShape({ 30, 30 });

        path.setPosition(Map::GetInstance().getPositionFromTile(convertVertixToMapTile(vertex)));
        path.setFillColor(sf::Color::Yellow);

        window->draw(path);
    }
#endif
}

//#TODO, STUDENTS: Build graph from map Tiles
Graph AIMoveBestRouteComponent::buildGraph() {
    const Map::TilesMapType& mapTiles = Map::GetInstance().getAllTiles();
    const unsigned numRows = mapTiles.size();
    const unsigned numCols = mapTiles[0].size();
    Graph graph(numRows * numCols);

    for (unsigned y = 0; y < numRows; ++y) {
        for (unsigned x = 0; x < numCols; ++x) {
            if (mapTiles[y][x]) continue;

            unsigned currentVertex = convertMapTileToVertix({ x, y });

            if (x > 0 && !mapTiles[y][x - 1]) {
                graph.addEdge(currentVertex, convertMapTileToVertix({ x - 1, y }));
            }
            if (x < numCols - 1 && !mapTiles[y][x + 1]) {
                graph.addEdge(currentVertex, convertMapTileToVertix({ x + 1, y }));
            }
            if (y > 0 && !mapTiles[y - 1][x]) {
                graph.addEdge(currentVertex, convertMapTileToVertix({ x, y - 1 }));
            }
            if (y < numRows - 1 && !mapTiles[y + 1][x]) {
                graph.addEdge(currentVertex, convertMapTileToVertix({ x, y + 1 }));
            }
        }
    }

    return graph;
}

void AIMoveBestRouteComponent::updatePath(Graph& graph)
{
    const sf::Vector2u referenceTile = Map::GetInstance().getTileFromPosition(m_referenceObject->getPosition());  //GetReferenceTile func
    const sf::Vector2u targetTile = Map::GetInstance().getTileFromPosition(m_targetObject->getPosition());    //GetTargetTile func

    const int start = convertMapTileToVertix(referenceTile);
    const int destination = convertMapTileToVertix(targetTile);

    std::vector<unsigned> path = graph.bfs(start, destination);

    m_path = path;
}

sf::Vector2u AIMoveBestRouteComponent::getNextTileToMove()
{
    if (m_path.size() < 2)
    {
        return Map::GetInstance().getTileFromPosition(m_referenceObject->getPosition());
    }

    return convertVertixToMapTile(m_path[1]);
}

//#TODO, STUDENTS: Implement algorithms to convert Map tiles in format [x, y] to graph vertex in format [idx],
//vertexes are formed sequentially from left to right from up to down,
// e.g. for tile [1, 3] with sizes [3*4] graph vertex is 7

//Here is an example of possible tile-vertex mappings
//00-0 01-1 02-2 03-3
//10-4 11-5 12-6 13-7
//20-8 21-9 22-10 23-11
//where 2 digits is tile description, and third digit is corresponding vertex in graph

unsigned AIMoveBestRouteComponent::convertMapTileToVertix(sf::Vector2u mapTile) const {
    return mapTile.y * Map::GetInstance().GetMapSize().x + mapTile.x;
}

sf::Vector2u AIMoveBestRouteComponent::convertVertixToMapTile(unsigned vertix) const {
    unsigned numCols = Map::GetInstance().GetMapSize().x;
    return { vertix % numCols, vertix / numCols };
}









